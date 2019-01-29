package main

import "workspacemanager"

import "dataformats"
import "dataworkspace"
import "dataprocesswrapper"

func main() {
	workspacemanager.Example()

	proc := dataprocesswrapper.NewDataProcessWrapper(
		dataformats.JSON,
		dataformats.JSON,
	)

	work := dataworkspace.NewDataWorkspace()
	work.AddProcess("a", proc)
}
