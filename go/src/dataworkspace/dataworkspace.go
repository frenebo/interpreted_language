package dataworkspace

import (
	"dataformats"
	"errors"
	"simplestdinstdoutcomponent"
	"strconv"
	"workspaceconnection"
	"workspaceio"
	"workspacepipe"
)

// DataWorkspace is holds the information about a data workspace
type DataWorkspace struct {
	simpleStdinStdoutComponents map[string]*simplestdinstdoutcomponent.SimpleStdinStdoutComponent
	connections                 []workspaceconnection.WorkspaceConnection
	inputs                      map[string]*workspaceio.WorkspaceInputComponent
	outputs                     map[string]*workspaceio.WorkspaceOutputComponent
}

func (workspace *DataWorkspace) hasComponentKey(key string) bool {
	_, simpleStdinStdoutCompExists := workspace.simpleStdinStdoutComponents[key]
	_, inputCompExists := workspace.inputs[key]
	_, outputCompExists := workspace.outputs[key]

	return simpleStdinStdoutCompExists || inputCompExists || outputCompExists
}

func (workspace *DataWorkspace) getComponentOutputType(key string) (dataformats.FormatType, error) {
	simpleStdinStdoutComp, hasVal := workspace.simpleStdinStdoutComponents[key]

	if hasVal {
		return simpleStdinStdoutComp.OutputFormat(), nil
	}

	inputComp, hasVal := workspace.inputs[key]

	if hasVal {
		return inputComp.GetDataFormat(), nil
	}

	return dataformats.ErrorType, errors.New("No component with an output that has key " + key + " found")
}

func (workspace *DataWorkspace) getComponentInputType(key string) (dataformats.FormatType, error) {
	simpleStdinStdoutComp, hasVal := workspace.simpleStdinStdoutComponents[key]

	if hasVal {
		return simpleStdinStdoutComp.InputFormat(), nil
	}

	outputComp, hasVal := workspace.outputs[key]

	if hasVal {
		return outputComp.GetDataFormat(), nil
	}

	return dataformats.ErrorType, errors.New("No component with an input that has key " + key + " found")
}

// WorkspaceInstance represents an instance of a data workspace, ready for input, etc.
type WorkspaceInstance struct {
	simpleStdinStdoutDataProcessHandles map[string]*simplestdinstdoutcomponent.SimpleStdinStdoutDataProcHandle
}

// CreateWorkspaceInstance creates a WorkspaceInstance from the data workspace
func (workspace *DataWorkspace) CreateWorkspaceInstance() (*WorkspaceInstance, error) {
	// @TODO check that everything is connected before running??

	// set up pipes
	pipesByOutput := make(map[string]*workspacepipe.WorkspacePipe)
	pipesByInput := make(map[string]*workspacepipe.WorkspacePipe)

	for i, conn := range workspace.connections {
		pipeName := strconv.Itoa(i)
		newPipe, err := conn.CreatePipe(pipeName)

		if err != nil {
			return nil, err
		}

		pipesByOutput[conn.GetOutputComponentId()] = newPipe
		pipesByInput[conn.GetInputComponentId()] = newPipe
	}

	// set up processes
	simpleStdinStdoutDataProcessHandles := make(map[string]*simplestdinstdoutcomponent.SimpleStdinStdoutDataProcHandle)

	for key, component := range workspace.simpleStdinStdoutComponents {
		newProcHandle, err := component.NewDataProcessHandle(
			pipesByOutput[key],
			pipesByInput[key],
		)

		if err != nil {
			return nil, err
		}

		simpleStdinStdoutDataProcessHandles[key] = newProcHandle
	}

	// set up inputs
	inputProcHandles := make(map[string]*workspaceio.WorkspaceInputProcessHandle)
	for key, component := range workspace.inputs {
		newInputProcHandle, err := component.NewProcessHandle(
			pipesByOutput[key],
		)

		if err != nil {
			return nil, err
		}

		inputProcHandles[key] = newInputProcHandle
	}

	// set up outputs
	outputProcHandles := make(map[string]*workspaceio.WorkspaceOutputProcessHandle)
	for key, component := range workspace.outputs {
		newOutputProcHandle, err := component.NewProcessHandle(
			pipesByInput[key],
		)

		if err != nil {
			return nil, err
		}

		outputProcHandles[key] = newOutputProcHandle
	}

	return &WorkspaceInstance{
		simpleStdinStdoutDataProcessHandles: simpleStdinStdoutDataProcessHandles,
	}, nil
}

// AddInput adds an input to the workspace
func (workspace *DataWorkspace) AddInput(key string, inputComponent *workspaceio.WorkspaceInputComponent) error {
	if workspace.hasComponentKey(key) {
		return errors.New("Component with given name already exists")
	}
	workspace.inputs[key] = inputComponent
	return nil
}

// AddOutput adds an output to the workspace
func (workspace *DataWorkspace) AddOutput(key string, outputComponent *workspaceio.WorkspaceOutputComponent) error {
	if workspace.hasComponentKey(key) {
		return errors.New("Component with given name already exists")
	}
	workspace.outputs[key] = outputComponent
	return nil
}

// AddComponent adds a component to the workspace
func (workspace *DataWorkspace) AddComponent(key string, component *simplestdinstdoutcomponent.SimpleStdinStdoutComponent) error {
	if workspace.hasComponentKey(key) {
		return errors.New("Component with given name already exists")
	}

	workspace.simpleStdinStdoutComponents[key] = component
	return nil
}

// AddConnection adds a connection between two components in the workspace
func (workspace *DataWorkspace) AddConnection(sourceKey string, targetKey string) error {
	sourceFormatType, err := workspace.getComponentOutputType(sourceKey)
	if err != nil {
		return err
	}

	targetFormatType, err := workspace.getComponentInputType(targetKey)
	if err != nil {
		return err
	}

	if sourceFormatType != targetFormatType {
		return errors.New("Connection has mismatching input and output types")
	}

	connection := workspaceconnection.NewWorkspaceConnection(sourceKey, targetKey, sourceFormatType)

	workspace.connections = append(workspace.connections, connection)

	return nil
}

// NewDataWorkspace creates a workspace
func NewDataWorkspace() *DataWorkspace {
	return &DataWorkspace{
		simpleStdinStdoutComponents: make(map[string]*simplestdinstdoutcomponent.SimpleStdinStdoutComponent),
		connections:                 []workspaceconnection.WorkspaceConnection{},
		inputs:                      make(map[string]*workspaceio.WorkspaceInputComponent),
		outputs:                     make(map[string]*workspaceio.WorkspaceOutputComponent),
	}
}
