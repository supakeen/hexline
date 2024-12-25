# hexline

A marquee of 32 16-segment characters.

> [!NOTE]  
> This project is a remix of the [hexboard](https://github.com/brainsmoke/hexboard) project by [brainsmoke](https://github.com/brainsmoke). Take a look to see what the project was originally designed to do, it's awesome.

![](image.jpg)

# Usage

> [!WARNING]  
> This firmware works (on `main`) but is in flux. I still want to add various other features and such.

Build and flash the firmware onto a Pi Pico. Connect the UART from the PCB to pin 4 on your Pi Pico. Make sure to tie SWDIO from the PCB to ground. When you plug in the Pi Pico to USB a new `/dev/ttyACMx` will appear. You can connect to it with your favorite serial emulator at 115200 baud; for example `screen /dev/ttyACM0 115200`.

You can then type and letters will appear. `\r` clears the screen.

# Components

## PCB

You can find the PCB for this at the [original project](https://github.com/brainsmoke/hexboard) in the `pcb/` subdirectory. The PCB contains an STM32 microcontroller that translates data that it receives over UART to the correct driving protocols for each of the segments.

## Firmware

The `hexline-ascii` firmware provides a Serial-over-USB interface that consumes ascii text. The firmware takes care of rendering to the segments for you.

You can run the firmware on a [Raspberry Pi Pico](...) with GPIO 4 connected to the UART on the PCB. If you want to fiddle with the firmware you can open their containing directories with the [Pico SDK](https://github.com/raspberrypi/pico-sdk) somewhere in your environment.
