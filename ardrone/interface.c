#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define MAXMSG 255

#define PORT 23
#define SERVER "192.168.1.1"

char msgbuf[255];

int isSetup=0;
int sock;
int player_num;

void catch_sigpipe (int sig);

char * write_to_server (char *message)
{
    int nbytes;
    char *response;
    response = (char*) malloc(MAXMSG);
    /*if(!isSetup)
    {
        setup();
    }*/
    printf("client sending %s\n",message);
    /*send request to server*/
    nbytes = write (sock, message, strlen (message) + 1);
    if (nbytes < 0)
    {
        perror ("write");
        //exit (EXIT_FAILURE);
        return 0;
    }
    /*read response*/
    nbytes = recv(sock, response, MAXMSG,0);
    printf("client got %s\n",response);
    return response;

}

void init_sockaddr (struct sockaddr_in *name, const char *hostname,uint16_t port)
{
    struct hostent *hostinfo;

    name->sin_family = AF_INET;
    name->sin_port = htons (port);
    hostinfo = gethostbyname (hostname);
    if (hostinfo == NULL)
    {
        fprintf (stderr, "Unknown host %s.\n", hostname);
        exit (EXIT_FAILURE);
    }
    name->sin_addr = *(struct in_addr *) hostinfo->h_addr;
}

void cleanup()
{
    close (sock);
}



void forward()
{
    char *response;
    sprintf(msgbuf,"/data/video/DroneClient /data/video/forward.ard\n");
    //printf("%s ",msgbuf);
    response=write_to_server(msgbuf);
    if(response!=NULL)
    {
        if(strstr(response,"ERROR")!=NULL)
        {
            printf("response: %s\n",response);
        }
        free(response);
    }
}

void back()
{
    char *response;
    sprintf(msgbuf,"/data/video/DroneClient /data/video/back.ard\n");
    //printf("%s ",msgbuf);
    response=write_to_server(msgbuf);
    if(response!=NULL)
    {
        if(strstr(response,"ERROR")!=NULL)
        {
            printf("response: %s\n",response);
        }
        free(response);
    }
}

void left()
{
    char *response;
    sprintf(msgbuf,"/data/video/DroneClient /data/video/left.ard\n");
    //printf("%s ",msgbuf);
    response=write_to_server(msgbuf);
    if(response!=NULL)
    {
        if(strstr(response,"ERROR")!=NULL)
        {
            printf("response: %s\n",response);
        }
        free(response);
    }
}

void right()
{
    char *response;
    sprintf(msgbuf,"/data/video/DroneClient /data/video/right.ard\n");
    //printf("%s ",msgbuf);
    response=write_to_server(msgbuf);
    if(response!=NULL)
    {
        if(strstr(response,"ERROR")!=NULL)
        {
            printf("response: %s\n",response);
        }
        free(response);
    }
}

void land()
{
    char *response;
    sprintf(msgbuf,"/data/video/DroneClient /data/video/land.ard\n");
    //printf("%s ",msgbuf);
    response=write_to_server(msgbuf);
    if(response!=NULL)
    {
        if(strstr(response,"ERROR")!=NULL)
        {
            printf("response: %s\n",response);
        }
        free(response);
    }
}


void setup ()
{
     int sockfd;
     struct sockaddr_in serv_addr;

     //set the sigpipe handler so we don't exit upon a sigpipe
     //this happens when we complete the course in tracksail and the tcp connection to it goes dead
     signal (SIGPIPE, catch_sigpipe);

     sockfd = socket(AF_INET, SOCK_STREAM, 0);

     if (sockfd < 0)
     {
        perror("ERROR opening socket");
     }


     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = inet_addr(SERVER);
     serv_addr.sin_port = htons(PORT);

     // extern void init_sockaddr (struct sockaddr_in *name, const char *hostname, uint16_t port);

    struct sockaddr_in servername;

    /* Create the socket. */
    sock = socket (PF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror ("socket (client)");
        exit (EXIT_FAILURE);
    }

    /* Connect to the server. */
    init_sockaddr (&servername, SERVER, PORT);
    if (0 > connect (sock, (struct sockaddr *) &servername,sizeof (servername)))
    {
        perror ("connect (client)");
        exit (EXIT_FAILURE);
    }

    isSetup=1;
}


void logout()
{
    char *response;
    sprintf(msgbuf,"exit");
    //printf("%s ",msgbuf);
    response=write_to_server(msgbuf);
    if(response!=NULL)
    {
        if(strstr(response,"ERROR")!=NULL)
        {
            printf("response: %s\n",response);
        }
        free(response);
    }
}


//signal handler for SIGPIPE, stops the program exiting upon a sig pipe
void catch_sigpipe (int sig)
{
    fprintf(stderr,"in sig handler, server disconnected");
    signal (sig, catch_sigpipe);
}

void main(int argc,char **argv)
{
  char * dir=argv[1];
 printf("connecting\n");
  setup();
  sleep(2);
  printf("connected\n");
  if(strstr(dir,"forward")!=NULL)
  {
    printf("forward\n");
    forward();
  }
  else if(strstr(dir,"back")!=NULL)
  {
    printf("back\n");
    back();
  }
  else if(strstr(dir,"left")!=NULL)
  {
    printf("left\n");
    left();
  }
  else if(strstr(dir,"right")!=NULL)
  {
    printf("right\n");
    right();
  }
  else if(strstr(dir,"stop"))
  {
    printf("stop\n");
    land();
  }
    printf("sent\n");
    sleep(8);
  logout();
 cleanup();
}