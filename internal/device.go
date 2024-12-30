package internal

import (
	"os"
)

func GetDeviceFile(path string) (*os.File, error) {
	f, err := os.OpenFile(path, os.O_RDWR, 0)

	if err != nil {
		return nil, err
	}

	if _, err := SetRate(f, 115200); err != nil {
		return nil, err
	}

	return f, nil
}
