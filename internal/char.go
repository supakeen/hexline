package internal

import (
	"fmt"
	"os"
	"time"
)

type CharDisplay struct {
	file *os.File
}

func NewCharDisplay(path string) (*CharDisplay, error) {
	f, err := GetDeviceFile(path)

	if err != nil {
		return nil, err
	}

	c := CharDisplay{
		file: f,
	}

	return &c, nil
}

func (c *CharDisplay) Display(text []string, delay int, keep bool) {
	for _, line := range text {
		c.file.Write([]byte(fmt.Sprintf("\r%s", line)))
		time.Sleep(time.Duration(delay) * time.Millisecond)
	}

	// If we're not keeping the text write a clear sequence at the end
	if !keep {
		c.file.Write([]byte("\r"))
	}
}
