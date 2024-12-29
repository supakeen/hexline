package internal

/*
#include <sys/ioctl.h>
#include <asm/termbits.h>

int set_rate(int fd, unsigned int rate) {
	struct termios2 tio;

	ioctl(fd, TCGETS2, &tio);

	tio.c_cflag &= ~(CBAUD);
	tio.c_cflag |= BOTHER;

	tio.c_ispeed = rate;
	tio.c_ospeed = rate;

	return ioctl(fd, TCSETS2, &tio);
}
*/
import "C"

import (
	"os"
)

/* Set the baudrate for a dev node file. */
func SetRate(f *os.File, rate int) (int, error) {
	ret, err := C.set_rate(C.int(f.Fd()), C.uint(rate))

	return int(ret), err
}
