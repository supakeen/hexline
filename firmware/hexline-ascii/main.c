// This file contains the firmware for 
//
// TODO:
// - [ ] Double buffering and switching?
// - [ ] Draw in the main loop?
// - [ ] Use DMA for the UART, same as emberpi, with a PIO for the UART and switching the frames around so we can
//       draw on the second buffer
// - [ ] Implement a nice fosforous glow effect?
//
// This file is licensed under the MIT license
//
// Copyright 2012 supakeen

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include "pico/stdlib.h"
#include "pico/stdio.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "area.h"
#include "disp.h"

#define DB 0xFF

char text[AREA_CHAR_C+1] = { 0 };
uint16_t area[2][AREA_SIZE] = { 0 };

void loop(void) {
    int p = 0;

    while(true) {
        int c = getchar_timeout_us(10);

        if(c == PICO_ERROR_TIMEOUT) {
            continue;
        }

        if(c == '\r') {
            p = 0;
            memset(text, 0, 33);
            continue;
        }

        if(p >= AREA_CHAR_C) {
            p = 0;
            memset(text, 0, AREA_CHAR_C+1);
        }

        text[p++] = c;
    }
}

bool draw_timer(__unused struct repeating_timer *_) {
    area_fade(area[0]);
    area_text_ltr(area[0], text);
    disp_draw(area[0]);

    return true;
}

int main() {
    stdio_init_all();

    // Drawing takes care of the communication with the display PCB, we draw
    // areas.
    disp_init();

    // Areas contain the values that we want to display.
    area_init();

    // Start with an empty area and draw it immediately, this gets rid of any
    // possible bits and bobs still on the display.
    area_clear(area[0]);
    disp_draw(area[0]);

    struct repeating_timer t;
    add_repeating_timer_ms(10, draw_timer, NULL, &t);

    loop();
}
