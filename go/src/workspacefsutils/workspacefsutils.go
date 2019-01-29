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
	os.Remove(path)
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

// AddNamedPipe creates a named pipe with the given path
func AddNamedPipe(pipeName string) {
	initRequiredDirsIfNotPresent()
	syscall.Mknod(namedPipeDir()+pipeName, syscall.S_IFIFO|0666, 0)
}
