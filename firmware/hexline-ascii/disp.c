#include "disp.h"
#include "area.h"

#include "pico/stdlib.h"

#include "hardware/pio.h"
#include "uart_tx.pio.h"

PIO pio;
uint sm;
uint offset;

void disp_init() {
    bool success = pio_claim_free_sm_and_add_program_for_gpio_range(
        &uart_tx_program,
        &pio,
        &sm,
        &offset,
        DISP_PIN,
        1,
        true);
    
    hard_assert(success);

    uart_tx_program_init(
        pio,
        sm,
        offset,
        DISP_PIN,
        DISP_BAUD);
}

void disp_draw(uint16_t *area) {
    uart_tx_program_puts(pio, sm, (char*) area, AREA_SIZE*2);
    uart_tx_program_puts(pio, sm, "\xFF\xFF\xFF\xF0", 4);
}
