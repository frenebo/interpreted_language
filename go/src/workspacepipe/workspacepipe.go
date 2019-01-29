package workspacepipe

import "dataformats"

// WorkspacePipe represents a pipe to use for the connection of two running processes
struct WorkspacePipe {
	dataFormat dataformats.FormatType
	namedPipePath string
}

func (wsPipe * WorkspacePipe) DataFormat() dataformats.FormatType {
	return wsPipe.dataFormat
}

func (wsPipe * WorkspacePipe) NamedPipePath() string {
	return wsPipe.namedPipePath
}
