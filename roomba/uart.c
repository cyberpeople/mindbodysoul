#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#include "uart.h"




/*Setup connection to the serial port*/
int uart_init(unsigned int baud,char *device)
{
    int fd;

    struct termios newtio;

    /*open serial port*/
    fd = open(device, O_RDWR | O_NOCTTY );

    if (fd <0)
    {
        fprintf(stderr,"Error opening device\n");
        exit(EXIT_FAILURE);
    }

    bzero(&newtio, sizeof(newtio));

    switch(baud)
    {
        case 300:
            newtio.c_cflag = B300 | CS8 | CLOCAL | CREAD;
            break;
        case 1200:
            newtio.c_cflag = B1200 | CS8 | CLOCAL | CREAD;
            break;
        case 2400:
            newtio.c_cflag = B2400 | CS8 | CLOCAL | CREAD;
            break;
        case 4800:
            newtio.c_cflag = B4800 | CS8 | CLOCAL | CREAD;
            break;
        case 9600:
            newtio.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
            break;
        case 19200:
            newtio.c_cflag = B19200 | CS8 | CLOCAL | CREAD;
            break;
        case 38400:
            newtio.c_cflag = B38400 | CS8 | CLOCAL | CREAD;
            break;
        case 57600:
            newtio.c_cflag = B57600 | CS8 | CLOCAL | CREAD;
            break;
        case 115200:
            newtio.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
            break;
        default:
            fprintf(stderr,"Invalid Baud Rate %d\n",baud);
            break;
    }
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;

    /* set input mode (non-canonical, no echo,...) */
    newtio.c_lflag = 0;

    newtio.c_cc[VTIME] = 50;   /* inter-character timer of 0.1 seconds */
    newtio.c_cc[VMIN]     = 1;   /* blocking read until 1 char received */
    /*flush out any old data*/
    tcflush(fd, TCIFLUSH);
    /*set baud rate etc*/
    tcsetattr(fd,TCSANOW,&newtio);
    //fprintf(stderr,"Opened device %s at %d bits per second\n",device,baud);

    return fd;
}

uint8_t uart_rx(int fd)
{
    char rec[1];
    ssize_t count;
#ifdef DEBUG
    rec[0]=test_data[test_data_count];    
    test_data_count++;
    if(test_data_count>=strlen(test_data))
    {
        test_data_count=0;
    }
#else
    /*get the response*/
    count=read(fd,rec,1);
    if(count!=1)
    {
        fprintf(stderr,"uart timeout\n");
        exit(1);
    }
#endif


    return rec[0];
}

void uart_tx(int fd,char data)
{
    write(fd,&data,1);
}

void uart_deinit(int fd)
{
    int status;
    status = close(fd);
    if(status==-1)
    {
        fprintf(stderr,"Error Closing file: %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }
}



