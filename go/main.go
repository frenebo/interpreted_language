package main

import (
	"dataformats"
	"dataworkspace"
	"fmt"
	"simplestdinstdoutcomponent"
	"time"
	"workspacefsutils"
	"workspaceio"
)

func main() {
	workspacefsutils.CleanUpAndInit()

	workspace := dataworkspace.NewDataWorkspace()

	firstComponent := simplestdinstdoutcomponent.NewSimpleStdinStdoutComponent(
		dataformats.PNG,
		dataformats.PNG,
		"python3",
		[]string{"simple_stdin_stdout_repeater.py"},
	)

	secondComponent := simplestdinstdoutcomponent.NewSimpleStdinStdoutComponent(
		dataformats.PNG,
		dataformats.PNG,
		"python3",
		[]string{"simple_stdin_stdout_repeater.py"},
	)

	err := workspace.AddInput("in", workspaceio.NewWorkspaceInputComponent(dataformats.PNG))
	if err != nil {
		fmt.Println(err)
		return
	}
	err = workspace.AddOutput("out", workspaceio.NewWorkspaceOutputComponent(dataformats.PNG))
	if err != nil {
		fmt.Println(err)
		return
	}

	err = workspace.AddComponent("1", firstComponent)
	if err != nil {
		fmt.Println(err)
		return
	}
	err = workspace.AddComponent("2", secondComponent)
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
	err = workspace.AddConnection("2", "out")
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
