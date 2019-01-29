package dataprocesswrapper

import (
	"dataformats"
	"os/exec"
)

// DataProcessWrapper is a wrapper for a running data process
type DataProcessWrapper struct {
	cmd          *exec.Cmd
	inputFormat  dataformats.FormatType
	outputFormat dataformats.FormatType
}

// NewDataProcessWrapper creates a data process
func NewDataProcessWrapper(
	inputFormat dataformats.FormatType,
	outputFormat dataformats.FormatType,
) *DataProcessWrapper {
	cmd := exec.Command("echo", "aaa")

	return &DataProcessWrapper{
		cmd:          cmd,
		inputFormat:  inputFormat,
		outputFormat: outputFormat,
	}
}
