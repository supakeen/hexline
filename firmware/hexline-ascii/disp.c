#include "disp.h"
#include "area.h"

#include "pico/stdlib.h"

#include "hardware/uart.h"

void disp_init() {
    uart_init(
        UART_ID,
        BAUD_RATE);

    gpio_set_function(
        UART_TX_PIN,
        GPIO_FUNC_UART);

    gpio_set_function(
        UART_RX_PIN,
        GPIO_FUNC_UART);

    uart_set_hw_flow(
        UART_ID,
        false,
        false);

    uart_set_format(
        UART_ID,
        8,
        1,
        UART_PARITY_NONE);

    uart_set_fifo_enabled(
        UART_ID,
        true);
}

void disp_draw(char *area) {
    uart_write_blocking(UART_ID, area, AREA_SIZE);
    uart_write_blocking(UART_ID, "\xFF\xFF\xFF\xF0", 4);
}