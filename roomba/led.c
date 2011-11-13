#include <stdio.h>
#include <unistd.h>
#include "uart.h"

void main()
{
	char commands3 [] = {139, 8,0,128}; 
	int num_of_commands3=4;
	int fd;

	for(int i=0;i<num_of_commands3;i++)
	{
		uart_tx(fd,commands3[i]);
	}
	uart_deinit(fd);
}
