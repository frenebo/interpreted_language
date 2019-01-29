package workspacefsutils

import (
	"os"
	"syscall"
)

func namedPipeDir() string {
	return "named_pipes/"
}

func isFilePath(path string) bool {
	stat, err := os.Stat(path)

	return err == nil && !stat.IsDir()
}

func deleteFileOrDir(path string) {
	os.RemoveAll(path)
}

func createDirAll(dirPath string) {
	os.MkdirAll(dirPath, os.ModePerm)
}

func isDirPath(path string) bool {
	stat, err := os.Stat(path)

	return err == nil && stat.IsDir()
}

func initRequiredDirsIfNotPresent() {
	requiredDirPathsArr := []string{
		namedPipeDir(),
	}

	for _, requiredDirPath := range requiredDirPathsArr {
		if isFilePath(requiredDirPath) {
			deleteFileOrDir(requiredDirPath)
			createDirAll(requiredDirPath)
		} else if !isDirPath(requiredDirPath) {
			createDirAll(requiredDirPath)
		}
	}
}

func cleanPipeDir() {
	deleteFileOrDir(namedPipeDir())
	createDirAll(namedPipeDir())
}

// CleanUpAndInit cleans up any old files and sets up new folders that may be missing
func CleanUpAndInit() {
	initRequiredDirsIfNotPresent()
	cleanPipeDir()
}

// AddNamedPipe creates a named pipe with the given path
func AddNamedPipe(pipeName string) error {
	return syscall.Mknod(PipePath(pipeName), syscall.S_IFIFO|0666, 0)
}

// PipePath gives the path of a pipe with the given name
func PipePath(pipeName string) string {
	return namedPipeDir() + pipeName
}
