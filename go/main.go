package main

import (
	"dataformats"
	"fmt"
	"simplestdinstdoutcomponent"
	"time"
	"workspacefsutils"
	"workspacepipe"
)

func main() {
	workspacefsutils.CleanUpAndInit()

	inputPipe, err := workspacepipe.NewWorkspacePipe(
		dataformats.JSON,
		"a",
	)
	fmt.Println(err)

	intermediatePipe, err := workspacepipe.NewWorkspacePipe(
		dataformats.JSON,
		"b",
	)
	fmt.Println(err)

	// outputPipe, err := workspacepipe.NewWorkspacePipe(
	// 	dataformats.JSON,
	// 	"c",
	// )
	// fmt.Println(err)

	component1 := simplestdinstdoutcomponent.NewSimpleStdinStdoutComponent(
		dataformats.JSON,
		dataformats.JSON,
		"python3",
		[]string{"prog.py"},
	)

	// component2 := simplestdinstdoutcomponent.NewSimpleStdinStdoutComponent(
	// 	dataformats.JSON,
	// 	dataformats.JSON,
	// 	"python3",
	// 	[]string{"prog.py"},
	// )

	component1.NewDataProcessHandle(
		inputPipe,
		intermediatePipe,
	)

	// component2.NewDataProcessHandle(
	// 	intermediatePipe,
	// 	outputPipe,
	// )

	for {
		time.Sleep(time.Second)
	}
}
