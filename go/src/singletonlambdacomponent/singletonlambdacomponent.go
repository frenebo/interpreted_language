package singletonlambdacomponent

import (
	"dataformats"
	"encoding/json"
	"io"
	"os/exec"
	"workspacepipe"
)

// SingletonLambdaComponent represents a singleton process that can take multiple "jobs"
type SingletonLambdaComponent struct {
	proc         *exec.Cmd
	inputFormat  dataformats.FormatType
	outputFormat dataformats.FormatType
	stdinPipe    io.WriteCloser
	stdoutPipe   io.ReadCloser
}

// SingletonTaskHandle represents a task being performed by a singleton process
type SingletonTaskHandle struct {
}

// NewSingletonLambdaComponent creates a new singleton lambda component, with a process and all
func NewSingletonLambdaComponent(
	cmdLine string,
	inputFormat dataformats.FormatType,
	outputFormat dataformats.FormatType,
) (*SingletonLambdaComponent, error) {
	proc := exec.Command(cmdLine)

	stdinPipe, err := proc.StdinPipe()
	if err != nil {
		return nil, err
	}

	stdoutPipe, err := proc.StdoutPipe()
	if err != nil {
		return nil, err
	}

	return &SingletonLambdaComponent{
		proc:         proc,
		stdinPipe:    stdinPipe,
		stdoutPipe:   stdoutPipe,
		inputFormat:  inputFormat,
		outputFormat: outputFormat,
	}, nil
}

type taskInstructionObject struct {
	InputPipeName  string
	OutputPipeName string
}

// CreateTaskHandle creates a handle for a task
func (component *SingletonLambdaComponent) CreateTaskHandle(
	inputPipe *workspacepipe.WorkspacePipe,
	outputPipe *workspacepipe.WorkspacePipe,
) (*SingletonTaskHandle, error) {
	encoded, err := json.Marshal(taskInstructionObject)
	if err != nil {
		return nil, err
	}

	_, err = component.stdinPipe.Write(encoded)
	if err != nil {
		return nil, err
	}

	return &SingletonTaskHandle{}, nil
}

// InputFormat returns the input type of the component
func (component *SingletonLambdaComponent) InputFormat() dataformats.FormatType {
	return component.inputFormat
}

// OutputFormat returns the output type of the component
func (component *SingletonLambdaComponent) OutputFormat() dataformats.FormatType {
	return component.outputFormat
}
