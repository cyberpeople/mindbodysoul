#include <stdint.h>

int uart_init(unsigned int baud,char *device);
void uart_deinit(int fd);
void uart_tx(int fd,char data);
uint8_t uart_rx(int fd);
