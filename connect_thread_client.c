#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <signal.h>
#define PORT 8080
int client_pid ,server_pid;
void *connect_thread(void *arg)
{
	struct sockaddr_in address;
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *hello = "Hello from client";
	char buffer[1024] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
// Convert IPv4 and IPv6 addresses from text to binary form

	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

	send(sock , hello , strlen(hello) , 0 );
	printf("Hello message sent\n");
	valread = read( sock , buffer, 1024);
	printf("%s\n",buffer );
    client_pid=getpid();
    send(sock,&client_pid,sizeof(int),0);
    printf("sent pid of client process\n");

	return (void*)NULL;

}
void SigUSR1_handler(int sig)
{
	printf ("get signal from the server\n");

}

int main(int argc, char const *argv[])
{

	signal(SIGUSR1,SigUSR1_handler);
 	pthread_t thread1;
	pthread_create(&thread1,NULL,connect_thread,"hello");
	int i=0;
	for (i=0;i<1000;i++)
	{
		sleep(1);
		printf("in gia tri thu %d\n",i);
	}
	pthread_join(thread1,NULL);
}
