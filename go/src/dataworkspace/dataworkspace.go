package dataworkspace

import (
	"dataformats"
	"errors"
	"simplestdinstdoutcomponent"
	"strconv"
	"workspaceconnection"
	"workspacepipe"
)

// DataWorkspace is holds the information about a data workspace
type DataWorkspace struct {
	simpleStdinStdoutComponents map[string]*simplestdinstdoutcomponent.SimpleStdinStdoutComponent
	connections                 []workspaceconnection.WorkspaceConnection
}

func (workspace *DataWorkspace) hasComponentKey(key string) bool {
	_, simpleStdinStdoutCompExists := workspace.simpleStdinStdoutComponents[key]

	return simpleStdinStdoutCompExists
}

func (workspace *DataWorkspace) getComponentOutputType(key string) (dataformats.FormatType, error) {
	simpleStdinStdoutComp, hasVal := workspace.simpleStdinStdoutComponents[key]

	if hasVal {
		return simpleStdinStdoutComp.OutputFormat(), nil
	}

	return dataformats.ErrorType, errors.New("No component with key " + key + " found")
}

func (workspace *DataWorkspace) getComponentInputType(key string) (dataformats.FormatType, error) {
	simpleStdinStdoutComp, hasVal := workspace.simpleStdinStdoutComponents[key]

	if hasVal {
		return simpleStdinStdoutComp.InputFormat(), nil
	}

	return dataformats.ErrorType, errors.New("No component with key " + key + " found")
}

// WorkspaceInstance represents an instance of a data workspace, ready for input, etc.
type WorkspaceInstance struct {
	simpleStdinStdoutDataProcessHandles map[string]*simplestdinstdoutcomponent.SimpleStdinStdoutDataProcHandle
}

// CreateWorkspaceInstance creates a WorkspaceInstance from the data workspace
func (workspace *DataWorkspace) CreateWorkspaceInstance() (*WorkspaceInstance, error) {
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

	return &WorkspaceInstance{
		simpleStdinStdoutDataProcessHandles: simpleStdinStdoutDataProcessHandles,
	}, nil
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

	workspacep = append(workspace.connections, connection)

	return nil
}

// NewDataWorkspace creates a workspace
func NewDataWorkspace() *DataWorkspace {
	return &DataWorkspace{
		simpleStdinStdoutComponents: make(map[string]*simplestdinstdoutcomponent.SimpleStdinStdoutComponent),
		connections:                 []workspaceconnection.WorkspaceConnection{},
	}
}
