package internal

import (
	"fmt"
	"os"
	"time"
)

type CutoffStrategy int

const (
	CutoffStrategyINVALID CutoffStrategy = iota
	CutoffStrategyCUT
	CutoffStrategySCROLL
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

func (c *CharDisplay) Display(text []string, delay int, strat CutoffStrategy, keep bool) {
	for _, line := range text {
		switch strat {
		case CutoffStrategyCUT:
			c.DisplayWithCutoff(line, 32)
			break
		case CutoffStrategySCROLL:
			c.DisplayWithScroll(line, 32)
			break
		}

		time.Sleep(time.Duration(delay) * time.Millisecond)
	}

	// If we're not keeping the text write a clear sequence at the end
	if !keep {
		c.file.Write([]byte("\r"))
	}
}

func (c *CharDisplay) DisplayWithCutoff(text string, length int) {
	if len(text) > length {
		text = text[:length]
	}

	c.file.Write([]byte(fmt.Sprintf("\r%s", text)))
}

func (c *CharDisplay) DisplayWithScroll(text string, length int) {
	if len(text) < length {
		c.file.Write([]byte(fmt.Sprintf("\r%s", text)))
	} else {
		var temp string

		for i := 0; i < (len(text) - length); i++ {
			temp = text[i : i+length]
			c.file.Write([]byte(fmt.Sprintf("\r%s", temp)))
			time.Sleep(time.Duration(100) * time.Millisecond)
		}
	}
}
