#include <stdio.h>
#include <unistd.h>
#include "uart.h"

void main()
{
	char command1[] = {128, 131};
	char commandF[] = {145, 255, 0, 255, 0};
	char commandB[] = {145, 0, 255, 0, 255};
	char commandL[] = {145, 0, 255, 0, 10};
	char commandRl[] = {145, 100, 0, 255, 0};

	int numCommands = 2;

	int fd;
	fd=uart_init(57600,"/dev/ttyUSB0");
	for (int i=0; i<numCommands;i++)
	{
		uart_tx(fd,command1[i]);
	}
	sleep(1);
	
	numCommands = 5;
	for (int i=0; i<numCommands; i++)
	{
		uart_tx(fd,commandF[i]);
	}
	sleep(2);

	for (int i=0; i<numCommands; i++)
	{
		uart_tx(fd,commandB[i]);
	}
	sleep(3);

	for (int i=0; i<numCommands; i++)
	{
		uart_tx(fd,commandL[i]);
	}
	sleep(5);

	for (int i=0; i<numCommands; i++)
	{
		uart_tx(fd,commandB[i]);
	}
	sleep(3);

	for (int i=0; i<numCommands; i++)
	{
		uart_tx(fd,commandRl[i]);
	}
	sleep(3);

	for (int i=0; i<numCommands; i++)
	{
		uart_tx(fd,commandF[i]);
	}
	sleep(5);

//stop

	char commands3 [] = {128, 131}; 
	char commands4 [] ={137, 0, 0, 0, 0};
	int num_of_commands3=2;
	int num_of_commands4=5;	
	//int fd;

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
