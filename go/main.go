package main

import (
	"dataformats"
	"dataworkspace"
	"simplestdinstdoutcomponent"
	"workspacefsutils"
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

	workspace.AddComponent("1", firstComponent)
	workspace.AddComponent("2", secondComponent)

	workspace.AddConnection("1", "2")

	workspace.CreateWorkspaceInstance()
}
