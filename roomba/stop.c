#include <stdio.h>
#include <unistd.h>
#include "uart.h"

void main()
{
	char commands3 [] = {128, 131}; 
	char commands4 [] ={137, 0, 0, 0, 0};
	//unsigned char commands[] = {128,132,139,2,0,0};
	int num_of_commands3=2;
	int num_of_commands4=5;	
	int fd;

	for(int i=0;i<num_of_commands3;i++)
	{
		uart_tx(fd,commands3[i]);
	}
	sleep(1);
	for(int i=0;i<num_of_commands4;i++)
	{
		uart_tx(fd,commands4[i]);
	}
	uart_deinit(fd);
}
