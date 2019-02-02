package main

import (
	"dataformats"
	"dataworkspace"
	"fmt"
	"simplestdinstdoutcomponent"
	"singletonlambdacomponent"
	"time"
	"workspacefsutils"
	"workspaceio"
)

func main() {
	workspacefsutils.CleanUpAndInit()

	workspace := dataworkspace.NewDataWorkspace()

	firstComponent := simplestdinstdoutcomponent.NewSimpleStdinStdoutComponent(
		dataformats.JSON,
		dataformats.JSON,
		"python3",
		[]string{"simple_stdin_stdout_repeater.py"},
	)

	secondComponent := simplestdinstdoutcomponent.NewSimpleStdinStdoutComponent(
		dataformats.JSON,
		dataformats.JSON,
		"python3",
		[]string{"simple_stdin_stdout_repeater.py"},
	)

	thirdComponent, err := singletonlambdacomponent.NewSingletonLambdaComponent(
		"python3",
		[]string{"singleton_json_multiplier.py"},
		dataformats.JSON,
		dataformats.JSON,
	)
	if err != nil {
		fmt.Println(err)
		return
	}

	err = workspace.AddInput("in", workspaceio.NewWorkspaceInputComponent(dataformats.JSON))
	if err != nil {
		fmt.Println(err)
		return
	}
	err = workspace.AddOutput("out", workspaceio.NewWorkspaceOutputComponent(dataformats.JSON))
	if err != nil {
		fmt.Println(err)
		return
	}

	err = workspace.AddSimpleStdinStdoutComponent("1", firstComponent)
	if err != nil {
		fmt.Println(err)
		return
	}
	err = workspace.AddSimpleStdinStdoutComponent("2", secondComponent)
	if err != nil {
		fmt.Println(err)
		return
	}
	err = workspace.AddSingletonLambdaComponent("3", thirdComponent)
	if err != nil {
		fmt.Println(err)
		return
	}

	err = workspace.AddConnection("in", "1")
	if err != nil {
		fmt.Println(err)
		return
	}
	err = workspace.AddConnection("1", "2")
	if err != nil {
		fmt.Println(err)
		return
	}
	err = workspace.AddConnection("2", "3")
	if err != nil {
		fmt.Println(err)
		return
	}
	err = workspace.AddConnection("3", "out")
	if err != nil {
		fmt.Println(err)
		return
	}

	_, err = workspace.CreateWorkspaceInstance()
	if err != nil {
		fmt.Println(err)
		return
	}

	for true {
		time.Sleep(time.Second)
	}
}
