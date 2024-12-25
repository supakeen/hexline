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

#include "area.h"

#include <string.h>
#include <stdint.h>

#define DB 0xFF00

inline void area_init(void) {}

inline void area_set_segment(uint16_t *area, uint16_t value) {
    if(value >= 0xFF00) value = 0xFF00;

    area[0] = value;
}

inline void area_set_letter(uint16_t *area, char letter) {
    switch(letter) {
        case ' ':
            break;
        case '?':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[7], DB);
            area_set_segment(&area[12], DB);
            break;
        case '0':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);

            break;
        case '1':
            area_set_segment(&area[9], DB);
            area_set_segment(&area[12], DB);

            break;
        case '2':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);

            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);

            break;
        case '3':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);

            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);

            break;
        case '4':
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);

            break;
        case '5':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[5], DB);

            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);

            break;
        case '6':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);

            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);

            break;

        case '7':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);

            break;
        case '8':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);

            break;
        case '9':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);

            break;
        case 'a':
        case 'A':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);

            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);

            break;
        case 'b':
        case 'B':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);

            area_set_segment(&area[7], DB);
            area_set_segment(&area[9], DB);
            area_set_segment(&area[12], DB);
            break;
        case 'c':
        case 'C':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            break;
        case 'd':
        case 'D':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[9], DB);
            area_set_segment(&area[12], DB);
            break;
        case 'e':
        case 'E':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            break;
        case 'f':
        case 'F':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            break;
        case 'g':
        case 'G':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[7], DB);
            break;
        case 'h':
        case 'H':
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);
            break;
        case 'i':
        case 'I':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[9], DB);
            area_set_segment(&area[12], DB);
            break;
        case 'j':
        case 'J':
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            break;
        case 'k':
        case 'K':
            area_set_segment(&area[2], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);
            area_set_segment(&area[10], DB);
            break;
        case 'l':
        case 'L':
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            break;
        case 'm':
        case 'M':
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[8], DB);
            area_set_segment(&area[10], DB);
            break;
        case 'n':
        case 'N':
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[8], DB);
            area_set_segment(&area[11], DB);
            break;
        case 'o':
        case 'O':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            break;
        case 'p':
        case 'P':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);
            break;
        case 'q':
        case 'Q':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[11], DB);
            break;
        case 'r':
        case 'R':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[1], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);
            area_set_segment(&area[11], DB);
            break;
        case 's':
        case 'S':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[7], DB);
            area_set_segment(&area[8], DB);
            break;
        case 't':
        case 'T':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[9], DB);
            area_set_segment(&area[12], DB);
            break;
        case 'u':
        case 'U':
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            break;
        case 'v':
        case 'V':
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[10], DB);
            area_set_segment(&area[13], DB);
            break;
        case 'w':
        case 'W':
            area_set_segment(&area[1], DB);
            area_set_segment(&area[2], DB);
            area_set_segment(&area[4], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[11], DB);
            area_set_segment(&area[13], DB);
            break;
        case 'x':
        case 'X':
            area_set_segment(&area[8], DB);
            area_set_segment(&area[10], DB);
            area_set_segment(&area[11], DB);
            area_set_segment(&area[13], DB);
            break;
        case 'y':
        case 'Y':
            area_set_segment(&area[1], DB);
            area_set_segment(&area[5], DB);
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);
            area_set_segment(&area[12], DB);
            break;
        case 'z':
        case 'Z':
            area_set_segment(&area[0], DB);
            area_set_segment(&area[3], DB);
            area_set_segment(&area[10], DB);
            area_set_segment(&area[13], DB);
            break;
        case '-':
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);
            break;
        case '_':
            area_set_segment(&area[3], DB);
            break;
        case '/':
            area_set_segment(&area[10], DB);
            area_set_segment(&area[13], DB);
            break;
        case '\\':
            area_set_segment(&area[8], DB);
            area_set_segment(&area[11], DB);
            break;
        case ',':
            area_set_segment(&area[13], DB);
            break;
        case '+':
            area_set_segment(&area[6], DB);
            area_set_segment(&area[7], DB);
            area_set_segment(&area[9], DB);
            area_set_segment(&area[12], DB);
            break;
        case '.':
            area_set_segment(&area[14], DB);
            break;
        default:
            area_set_segment(&area[0], 0xFFFF);
    }
}


inline void area_clear(uint16_t *area) {
    memset(area, 0, AREA_SIZE * sizeof(uint16_t));
}

inline void area_text_ltr(uint16_t *area, char *text) {
    for(int i = 0; i < strlen(text) && i < AREA_CHAR_C; i++) {
        area_set_letter(&area[i*16], text[i]);
    }
}

inline void area_fade(uint16_t *area) {
    for(int i = 0; i < AREA_SIZE; i++) {
        area[i] = area[i] * 0.5;
    }
}
