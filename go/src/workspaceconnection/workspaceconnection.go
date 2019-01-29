package workspaceconnection

import "dataformats"

// WorkspaceConnection describes a connection between two components in the workspace
struct WorkspaceConnection {
	inputComponentId  string
	outputComponentId string
	dataFormat        dataformats.FormatType
}
