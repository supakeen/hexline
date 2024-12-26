#include "disp.h"
#include "cmap.h"

#include "pico/stdlib.h"

#include "hardware/pio.h"
#include "uart_tx.pio.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DB 0xFF00

PIO pio;
uint sm;
uint offset;

struct disp* disp_init(uint8_t mode) {
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

    struct disp *D = malloc(sizeof(struct disp));

    hard_assert(D != NULL);

    D->mode = mode;

    return D;
}

// Clear the display, call `disp_draw` after.
void disp_clear(struct disp *D) {
    memset(D->area, 0, AREA_SIZE * sizeof(uint16_t));
}

// Set a single segment to a clamped value.
void disp_set(struct disp *D, int p, uint16_t v) {
    if(v >= 0xFF00) v = 0xFF00;
    D->area[p] = v;
}

// Send over the internal area buffer to the connected screen.
void disp_draw(struct disp *D) {
    uart_tx_program_puts(pio, sm, (char*) D->area, AREA_SIZE*2);
    uart_tx_program_puts(pio, sm, "\xFF\xFF\xFF\xF0", 4);
}

// Write a `char*` to the display up to a maximum of the display size.
void disp_char_set(struct disp *D, char *text) {
    hard_assert(D->mode == DISP_MODE_CHAR);

    for(int i = 0; i < strlen(text) && i < AREA_CHAR_C; i++) {
        disp_char_set_at_position(D, i, text[i]);
    }
}

// Set a character at a specific position. This handles translating the
// character to its offset in segments and translating a character to the
// segments it consists of through a 'character map'.
void disp_char_set_at_position(struct disp* D, int p, char c) {
    hard_assert(D->mode == DISP_MODE_CHAR);

    // Characters are stored in a 'character map', an array of size CHAR_MAX that
    // contains 16-length uint16_t arrays with the segments to turn on/off for each
    // character in the ASCII set.

    if(cmap[c] == NULL) {
        // When a character is NULL in the cmap then we don't support the character,
        // we have two options here; don't write at all (and skip it), or give some
        // sort of input to the user; in this case we write a specific 'unknown
        // character' to display.

        memcpy(&D->area[p*16], (uint16_t[16]){ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 32);
    } else {
        // Otherwise we can memcpy in the character

        memcpy(&D->area[p*16], cmap[c], 32);
    }
}
