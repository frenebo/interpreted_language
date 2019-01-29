package dataprocesswrapper

import "dataformats"

// DataProcessWrapper is a wrapper for a running data process
type DataProcessWrapper struct {
	inputFormat  dataformats.FormatType
	outputFormat dataformats.FormatType
}

// NewDataProcessWrapper creates a data process
func NewDataProcessWrapper(
	inputFormat dataformats.FormatType,
	outputFormat dataformats.FormatType,
) *DataProcessWrapper {
	return &DataProcessWrapper{
		inputFormat:  inputFormat,
		outputFormat: outputFormat,
	}
}
