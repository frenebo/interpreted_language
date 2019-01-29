package dataworkspace

import "dataprocesswrapper"

// DataWorkspace is holds the information about a data workspace
type DataWorkspace struct {
	processes map[string]*dataprocesswrapper.DataProcessWrapper
}

// AddProcess adds a process to the workspace
func (workspace *DataWorkspace) AddProcess(key string, proc *dataprocesswrapper.DataProcessWrapper) {
	workspace.processes[key] = proc
}

// NewDataWorkspace creates a workspace
func NewDataWorkspace() *DataWorkspace {
	return &DataWorkspace{
		processes: make(map[string]*dataprocesswrapper.DataProcessWrapper),
	}
}
