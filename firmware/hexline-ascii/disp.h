#ifndef DRAW_H
#define DRAW_H

#include <stdint.h>

#define UART_ID uart1
#define BAUD_RATE 1500000

#define UART_TX_PIN 4
#define UART_RX_PIN 5

void disp_init(void);
void disp_draw(uint16_t*);

#endif
