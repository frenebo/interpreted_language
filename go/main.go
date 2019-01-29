package main

import (
	"dataformats"
	"simplestdinstdoutcomponent"
	"time"
)

func main() {
	comp := simplestdinstdoutcomponent.NewSimpleStdinStdoutComponent(
		dataformats.JSON,
		dataformats.JSON,
		"python3",
		[]string{"prog.py"},
	)

	comp.NewDataProcessHandle()

	for {
		time.Sleep(time.Second)
	}
}
