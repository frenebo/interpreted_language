package datacomponent

import "dataformats"
import "dataprocesshandle"
import "workspacepipe"

// DataComponent represents a component of the data flow graph
type DataComponent interface {
	InputFormat() dataformats.FormatType
	OutputFormat() dataformats.FormatType

	NewDataProcessHandle(
		inputPipe workspacepipe.WorkspacePipe,
		outputPipe workspacepipe.WorkspacePipe,
	) (*dataprocesshandle.DataProcessHandle, error)
}
