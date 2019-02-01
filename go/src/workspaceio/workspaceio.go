package workspaceio

import "workspacepipe"
import "dataformats"

// WorkspaceInputComponent represents an input to a workspace plan
type WorkspaceInputComponent struct {
	dataFormat dataformats.FormatType
}

func (component *WorkspaceInputComponent) GetDataFormat() dataformats.FormatType {
	return component.dataFormat
}

// WorkspaceOutputComponent represents an output to a workspace plan
type WorkspaceOutputComponent struct {
	dataFormat dataformats.FormatType
}

func (component *WorkspaceOutputComponent) GetDataFormat() dataformats.FormatType {
	return component.dataFormat
}

// NewWorkspaceInputComponent creates a WorkspaceInputComponent for use in a workspace
func NewWorkspaceInputComponent(dataFormat dataformats.FormatType) *WorkspaceInputComponent {
	return &WorkspaceInputComponent{
		dataFormat: dataFormat,
	}
}

// NewWorkspaceOutputComponent creates a WorkspaceInputComponent for use in a workspace
func NewWorkspaceOutputComponent(dataFormat dataformats.FormatType) *WorkspaceOutputComponent {
	return &WorkspaceOutputComponent{
		dataFormat: dataFormat,
	}
}

// WorkspaceInputProcessHandle represents an input to a workspace plan
type WorkspaceInputProcessHandle struct {
}

// WorkspaceOutputProcessHandle represents an output to a workspace plan
type WorkspaceOutputProcessHandle struct {
}

// NewProcessHandle creates workspace input process handle
func (component *WorkspaceInputComponent) NewProcessHandle(
	pipe *workspacepipe.WorkspacePipe,
) (*WorkspaceInputProcessHandle, error) {
	_ = pipe
	return &WorkspaceInputProcessHandle{}, nil
}

// NewProcessHandle creates workspace output process handle
func (component *WorkspaceOutputComponent) NewProcessHandle(
	pipe *workspacepipe.WorkspacePipe,
) (*WorkspaceOutputProcessHandle, error) {
	_ = pipe
	return &WorkspaceOutputProcessHandle{}, nil
}
