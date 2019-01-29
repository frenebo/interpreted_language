package main

import "dataprocesswrapper"
import "dataformats"

func main() {
	// processutils.SpawnProcess()
	dataprocesswrapper.NewDataProcessWrapper(
		dataformats.JSON,
		dataformats.JSON,
	)

	// workspacefsutils.CleanUpAndInit()

	// work := dataworkspace.NewDataWorkspace()
	// work.AddProcess("a", proc)
}
