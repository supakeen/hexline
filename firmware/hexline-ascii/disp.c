#include "disp.h"

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
void disp_text_set(struct disp *D, char *text) {
    hard_assert(D->mode == DISP_MODE_CHAR);

    for(int i = 0; i < strlen(text) && i < AREA_CHAR_C; i++) {
        disp_text_set_at_position(D, i, text[i]);
    }
}

// Set a character at a specific position. This handles translating the
// character to its offset in segments and translating a character to the
// segments it consists of. A bit of a multi-purpose function that should
// probably be split out.
void disp_text_set_at_position(struct disp* D, int p, char c) {
    hard_assert(D->mode == DISP_MODE_CHAR);

    uint16_t *area = &D->area[p*16];

    p = p * 16;

    switch(c) {
        case ' ':
            break;
        case '?':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 7, DB);
            disp_set(D, p + 12, DB);
            break;
        case '0':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);

            break;
        case '1':
            disp_set(D, p + 9, DB);
            disp_set(D, p + 12, DB);

            break;
        case '2':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);

            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);

            break;
        case '3':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);

            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);

            break;
        case '4':
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);

            break;
        case '5':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 5, DB);

            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);

            break;
        case '6':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);

            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);

            break;

        case '7':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);

            break;
        case '8':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);

            break;
        case '9':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);

            break;
        case 'a':
        case 'A':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);

            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);

            break;
        case 'b':
        case 'B':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);

            disp_set(D, p + 7, DB);
            disp_set(D, p + 9, DB);
            disp_set(D, p + 12, DB);
            break;
        case 'c':
        case 'C':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            break;
        case 'd':
        case 'D':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 9, DB);
            disp_set(D, p + 12, DB);
            break;
        case 'e':
        case 'E':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            break;
        case 'f':
        case 'F':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            break;
        case 'g':
        case 'G':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 7, DB);
            break;
        case 'h':
        case 'H':
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);
            break;
        case 'i':
        case 'I':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 9, DB);
            disp_set(D, p + 12, DB);
            break;
        case 'j':
        case 'J':
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            break;
        case 'k':
        case 'K':
            disp_set(D, p + 2, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);
            disp_set(D, p + 10, DB);
            break;
        case 'l':
        case 'L':
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            break;
        case 'm':
        case 'M':
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 8, DB);
            disp_set(D, p + 10, DB);
            break;
        case 'n':
        case 'N':
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 8, DB);
            disp_set(D, p + 11, DB);
            break;
        case 'o':
        case 'O':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            break;
        case 'p':
        case 'P':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);
            break;
        case 'q':
        case 'Q':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 11, DB);
            break;
        case 'r':
        case 'R':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 1, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);
            disp_set(D, p + 11, DB);
            break;
        case 's':
        case 'S':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 7, DB);
            disp_set(D, p + 8, DB);
            break;
        case 't':
        case 'T':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 9, DB);
            disp_set(D, p + 12, DB);
            break;
        case 'u':
        case 'U':
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            break;
        case 'v':
        case 'V':
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 10, DB);
            disp_set(D, p + 13, DB);
            break;
        case 'w':
        case 'W':
            disp_set(D, p + 1, DB);
            disp_set(D, p + 2, DB);
            disp_set(D, p + 4, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 11, DB);
            disp_set(D, p + 13, DB);
            break;
        case 'x':
        case 'X':
            disp_set(D, p + 8, DB);
            disp_set(D, p + 10, DB);
            disp_set(D, p + 11, DB);
            disp_set(D, p + 13, DB);
            break;
        case 'y':
        case 'Y':
            disp_set(D, p + 1, DB);
            disp_set(D, p + 5, DB);
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);
            disp_set(D, p + 12, DB);
            break;
        case 'z':
        case 'Z':
            disp_set(D, p + 0, DB);
            disp_set(D, p + 3, DB);
            disp_set(D, p + 10, DB);
            disp_set(D, p + 13, DB);
            break;
        case '-':
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);
            break;
        case '_':
            disp_set(D, p + 3, DB);
            break;
        case '/':
            disp_set(D, p + 10, DB);
            disp_set(D, p + 13, DB);
            break;
        case '\\':
            disp_set(D, p + 8, DB);
            disp_set(D, p + 11, DB);
            break;
        case ',':
            disp_set(D, p + 13, DB);
            break;
        case '+':
            disp_set(D, p + 6, DB);
            disp_set(D, p + 7, DB);
            disp_set(D, p + 9, DB);
            disp_set(D, p + 12, DB);
            break;
        case '.':
            disp_set(D, p + 14, DB);
            break;

        default:
            disp_set(D, p, 0xFF00);
    }
}
