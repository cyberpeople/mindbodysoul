#include <stdio.h>
#include <unistd.h>
#include "uart.h"

void main()
{
	char commands[] = {128, 131 };
	char commands2[] = { 145, 255, 0, 255, 0};
	//char commands2[] = {152, 13, 137, 1, 44, 128, 0, 156, 1, 144, 137, 0, 0, 0, 0};
	int num_of_commands=2;
	int num_of_commands2=5;	

	int fd;
	fd=uart_init(57600,"/dev/ttyUSB0");
	for(int i=0;i<num_of_commands;i++)
	{
		uart_tx(fd,commands[i]);
	}
	sleep(1);
	for(int i=0;i<num_of_commands2;i++)
	{
		uart_tx(fd,commands2[i]);
	}
        sleep(5);
	printf("stopping\n");
//stop
	char commands3 [] = {128, 131}; 
	char commands4 [] ={145, 0, 0, 0, 0};
	//unsigned char commands[] = {128,132,139,2,0,0};
	int num_of_commands3=2;
	int num_of_commands4=5;	

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
