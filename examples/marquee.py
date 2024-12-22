#!/usr/bin/env python3
import serial
import sys
import time


def main():
    with serial.Serial(
        port="/dev/ttyACM0",
        baudrate=1500000,
    ) as port:
        port.write(b"\r")

        data = " " * 32 + sys.argv[1] + " " * 32
        data = data.encode("utf8")

        for i in range(len(data)):
            port.write(data[i:i+32])
            time.sleep(0.2)

        port.write(b"\r")
        port.flush()


if __name__ == "__main__":
    raise SystemExit(main())
