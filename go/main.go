package main

import "workspacefsutils"
import "dataformats"
import "dataworkspace"
import "dataprocesswrapper"

func main() {

	proc := dataprocesswrapper.NewDataProcessWrapper(
		dataformats.JSON,
		dataformats.JSON,
	)

	workspacefsutils.CleanUpAndInit()

	work := dataworkspace.NewDataWorkspace()
	work.AddProcess("a", proc)
}
