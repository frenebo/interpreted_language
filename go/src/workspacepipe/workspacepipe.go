package workspacepipe

import (
	"dataformats"
	"workspacefsutils"
)

// WorkspacePipe represents a pipe to use for the connection of two running processes
type WorkspacePipe struct {
	dataFormat dataformats.FormatType
	pipeName   string
}

// DataFormat gives the format of data this pipe carries
func (wsPipe *WorkspacePipe) DataFormat() dataformats.FormatType {
	return wsPipe.dataFormat
}

// PipeName gives the path of the pipe
func (wsPipe *WorkspacePipe) PipeName() string {
	return wsPipe.pipeName
}

// NewWorkspacePipe creates a workspace pipe
func NewWorkspacePipe(
	dataFormat dataformats.FormatType,
	pipeName string,
) (*WorkspacePipe, error) {
	err := workspacefsutils.AddNamedPipe(pipeName)
	return &WorkspacePipe{
		dataFormat: dataFormat,
		pipeName:   pipeName,
	}, err
}
