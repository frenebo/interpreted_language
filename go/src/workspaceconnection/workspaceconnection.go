package workspaceconnection

import "dataformats"
import "workspacepipe"

// WorkspaceConnection describes a connection between two components in the workspace
type WorkspaceConnection struct {
	inputComponentId  string
	outputComponentId string
	dataFormat        dataformats.FormatType
}

func (connection *WorkspaceConnection) GetInputComponentId() string {
	return connection.inputComponentId
}

func (connection *WorkspaceConnection) GetOutputComponentId() string {
	return connection.outputComponentId
}

func (connection *WorkspaceConnection) GetDataFormat() dataformats.FormatType {
	return connection.dataFormat
}

// CreatePipe creates a pipe from the connection
func (connection *WorkspaceConnection) CreatePipe(pipeName string) (*workspacepipe.WorkspacePipe, error) {
	return workspacepipe.NewWorkspacePipe(
		connection.dataFormat,
		pipeName,
	)
}

// NewWorkspaceConnection creates a workspace connection struct
func NewWorkspaceConnection(inputComponentId string, outputComponentId string, dataFormat dataformats.FormatType) WorkspaceConnection {
	return WorkspaceConnection{
		inputComponentId:  inputComponentId,
		outputComponentId: outputComponentId,
		dataFormat:        dataFormat,
	}
}
