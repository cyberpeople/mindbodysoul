#include <stdio.h>
#include <unistd.h>
#include "uart.h"

void main()
{
	char command1[] = {128, 131};
	char commandB[] = {145, 0, 100, 0, 100};
	char commandF[] = {145, 255, 0, 255, 0};
	char commandR1[] = {145, 200, 0, 255, 0};
	char commandR2[] = {145, 160, 0, 255, 0};
	char commandR3[] = {145, 120, 0, 255, 0};
	char commandR4[] = {145, 80, 0, 255, 0};
	char commandR5[] = {145, 40, 0, 255, 0};
	char commandR6[] = {145, 10, 0, 255, 0};

	char commandL[] = {145, 0, 255, 0, 150};

	int numCommands = 2;

	int fd;
	fd=uart_init(57600,"/dev/ttyUSB0");
	for (int i=0; i<numCommands;i++)
	{
		uart_tx(fd,command1[i]);
	}
	sleep(1);

	numCommands = 5;
	
	for (int i=0; i<numCommands;i++)
	{
		uart_tx(fd,commandF[i]);
	}
	sleep(4);
	
	for (int i=0; i<numCommands;i++)
	{
		uart_tx(fd,commandR1[i]);
	}
	sleep(4);

	for (int i=0; i<numCommands;i++)
	{
		uart_tx(fd,commandR2[i]);
	}
	sleep(4);

	for (int i=0; i<numCommands;i++)
	{
		uart_tx(fd,commandR3[i]);
	}
	sleep(4);

	for (int i=0; i<numCommands;i++)
	{
		uart_tx(fd,commandR4[i]);
	}
	sleep(4);

	for (int i=0; i<numCommands;i++)
	{
		uart_tx(fd,commandR5[i]);
	}
	sleep(4);

	for (int i=0; i<numCommands;i++)
	{
		uart_tx(fd,commandR6[i]);
	}
	sleep(4);

}
