package dataprocesshandle

import "dataformats"

// DataProcessHandle is an interface for interacting with an "instance" of a data process
type DataProcessHandle interface {
	InputFormat() dataformats.FormatType
	OutputFormat() dataformats.FormatType
}
