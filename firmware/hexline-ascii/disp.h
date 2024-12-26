#ifndef DRAW_H
#define DRAW_H

#include <stdlib.h>
#include <stdint.h>

#define DISP_PIN 4
#define DISP_BAUD 1500000

#define AREA_CHAR_C 32  // there are 32 characters per area

#define AREA_SEG_C 16   // and each character has 16 segments
#define AREA_SEG_W 2    // and each segment has a width of 2 bytes (16-bits)

// giving us a total width of CHAR_C * SEG_C * SEG_W plus
// the end of frame marker (4)
#define AREA_SIZE AREA_CHAR_C * AREA_SEG_C

#define DISP_MODE_CHAR 0
#define DISP_MODE_UI16 1

struct disp {
    uint8_t mode;
    uint16_t area[AREA_SIZE];
};

struct disp* disp_init(uint8_t);

void disp_draw(struct disp*);
void disp_clear(struct disp*);

void disp_char_set(struct disp*, char*);
void disp_char_set_at_position(struct disp*, int, char);



#endif