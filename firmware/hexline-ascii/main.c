// This file is licensed under the MIT license
//
// Copyright 2024 Simon de Vlieger

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
#include "pico/multicore.h"

#include <tusb.h>

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "disp.h"

#define DB 0xFF

char     text[AREA_CHAR_C+1] = { 0 };

struct disp *D = { 0 };

// Busy loop over serial input, if we receive any we add it to the text
// buffer which is smashed into the area in the correct format on every
// execution of `draw_timer` (see below).
void loop(void) {
    int p = 0;

    while(true) {
        int c = getchar_timeout_us(10);

        // Retry when there wasn't any character available.
        if(c == PICO_ERROR_TIMEOUT) {
            continue;
        }

        // If enter, clear screen.
        if(c == '\r') {
            p = 0;
            memset(text, 0, 33);
            continue;
        }

        // If text too long, wrap around.
        if(p >= AREA_CHAR_C) {
            p = 0;
            memset(text, 0, AREA_CHAR_C+1);
        }

        // Write the text to the buffer.
        text[p++] = c;
    }
}

// core0 is dedicated to receiving (and formatting, if necessary_data
void main_core0(void) {
    tusb_init();

    loop();
}

// core1 is dedicated to drawing the display in a loop, we want to split this out
// later when we do double buffering again.
void main_core1(void) {
    while(1) {
        disp_clear(D);
        disp_char_set(D, text);
        disp_draw(D);
    }
}

int main() {
    stdio_init_all();

    D = disp_init(DISP_MODE_CHAR);

    multicore_launch_core1(main_core1);

    main_core0();
}
