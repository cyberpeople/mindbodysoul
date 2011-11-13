#include <stdio.h>
#include "uart.h"

void main()
{
	char commands[] = {10,128,0,0};
	int num_of_commands=4;

	int fd;
	fd=uart_init("/dev/ttyUSB0","57600");
	for(int i=0;i<num_of_commands;i++)
	{
		uart_tx(fd,commands[i]);
	}
	uart_deinit(fd);
}
