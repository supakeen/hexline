#ifndef MUSB_H
#define MUSB_H

#include <stdint.h>

#define USB_BUFFER_SIZE 1024

#define USB_CHAR_INTERFACE 0
#define USB_BYTE_INTERFACE 1

void usb_char_read(uint8_t);
void usb_byte_read(uint8_t);

void usb_char_loop(uint8_t);
void usb_byte_loop(uint8_t);

void usb_loop(uint8_t);
void usb_init(uint8_t);

#endif
