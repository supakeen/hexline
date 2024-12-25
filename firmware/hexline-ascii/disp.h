#ifndef DRAW_H
#define DRAW_H

#include <stdint.h>

#define DISP_PIN 4
#define DISP_BAUD 1500000

void disp_init(void);
void disp_draw(uint16_t*);

#endif
