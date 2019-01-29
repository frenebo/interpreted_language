package simplestdinstdoutcomponent

import (
	"dataformats"
	"os/exec"
)

// SimpleStdinStdoutDataProcHandle is a handle for a simple stdin-stdout file process
type SimpleStdinStdoutDataProcHandle struct {
	proc         *exec.Cmd
	inputFormat  dataformats.FormatType
	outputFormat dataformats.FormatType
}

// InputFormat returns the process handle's input format
func (handle *SimpleStdinStdoutDataProcHandle) InputFormat() dataformats.FormatType {
	return handle.inputFormat
}

// OutputFormat returns the process handle's output format
func (handle *SimpleStdinStdoutDataProcHandle) OutputFormat() dataformats.FormatType {
	return handle.outputFormat
}

// SimpleStdinStdoutComponent is a component for a simple process that takes stdin and returns stdout, with one
// process being started for every input, returning the output and then closing
type SimpleStdinStdoutComponent struct {
	inputFormat  dataformats.FormatType
	outputFormat dataformats.FormatType
	cmdString    string
	cmdArgs      []string
}

// NewDataProcessHandle creates a process handle
func (component *SimpleStdinStdoutComponent) NewDataProcessHandle(
	inputPipe workspacepipe.WorkspacePipe,
	outputPipe workspacepipe.WorkspacePipe
) *SimpleStdinStdoutDataProcHandle {
	// "(cat < inputpipe) > outputpipe"
	// inputPipe.
	// proc := exec.Command(component.cmdString, component.cmdArgs...)

	return &SimpleStdinStdoutDataProcHandle{
		inputFormat:  component.inputFormat,
		outputFormat: component.outputFormat,
		proc:         proc,
	}
}

// InputFormat returns the input type of the component
func (component *SimpleStdinStdoutComponent) InputFormat() dataformats.FormatType {
	return component.inputFormat
}

// OutputFormat returns the output type of the component
func (component *SimpleStdinStdoutComponent) OutputFormat() dataformats.FormatType {
	return component.outputFormat
}

// NewSimpleStdinStdoutComponent creates a new simple stdin stdout component
func NewSimpleStdinStdoutComponent(
	inputFormat dataformats.FormatType,
	outputFormat dataformats.FormatType,
	cmdString string,
	cmdArgs []string,
) *SimpleStdinStdoutComponent {
	return &SimpleStdinStdoutComponent{
		inputFormat:  inputFormat,
		outputFormat: outputFormat,
		cmdString:    cmdString,
		cmdArgs:      cmdArgs,
	}
}
