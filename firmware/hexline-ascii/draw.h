#ifndef DRAW_H
#define DRAW_H

#define UART_ID uart1
#define BAUD_RATE 1500000

#define UART_TX_PIN 4
#define UART_RX_PIN 5

void draw_init(void);
void draw(char*);

#endif