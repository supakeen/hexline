#include <stdint.h>

#include <tusb.h>

#include "musb.h"

uint8_t  usb_char_b[USB_BUFFER_SIZE];
uint32_t usb_char_p;

uint8_t  usb_byte_b[USB_BUFFER_SIZE];
uint32_t usb_byte_p;

void usb_char_read(void) {
    uint32_t n = tud_cdc_n_available(USB_CHAR_INTERFACE);

    if(n) {
        uint32_t m = MIN(n, USB_BUFFER_SIZE - usb_char_p);
        uint32_t c = tud_cdc_n_read(USB_CHAR_INTERFACE, buffer, n);

        usb_char_p += c;
    }
}

void usb_byte_read(void) {
    uint32_t n = tud_cdc_n_available(USB_BYTE_INTERFACE);

    if(n) {
        uint32_t m = MIN(n, USB_BUFFER_SIZE - usb_byte_p);
        uint32_t c = tud_cdc_n_read(USB_BYTE_INTERFACE, buffer, n);

        usb_byte_p += c;
    }
}

void usb_char_loop(void) {
    if(tud_cdc_connected(USB_CHAR_INTERFACE)) {
        usb_char_read();
    }
}

void usb_byte_loop(void) {
    if(tud_cdc_connected(USB_BYTE_INTERFACE)) {
        usb_byte_read();
    }
}

void usb_loop(uint8_t interface) {
    tud_task();

    usb_char_loop();
    usb_byte_loop();
}

void usb_init(void) {
    tusb_init();
}
