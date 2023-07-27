#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct sockaddr_in serv_addr,cli_addr;
int listenfd,connfd,r,w,val,cli_addr_len;
unsigned short serv_port=25069;
char serv_ip[]="127.0.0.1";
char buff[128];
int main()
{
	/*initializing server socket address structure with zero values
	*/
	bzero(&serv_addr,sizeof(serv_addr));
	//filling up the server socket adress structure with appropriate value
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(serv_port);
	inet_aton(serv_ip,(&serv_addr.sin_addr));
	
	printf("\nUDP ECHO SERVER.\n");
	
	//creating socket
	listenfd= socket(AF_INET, SOCK_DGRAM, 0);

	if(listenfd<0)
	{
		printf("\nSERVER ERROR: can't careate socket\n");
		exit(1);
	}
//Binding server socket
	if(bind(listenfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("\nSERVER ERROR:cannot bind\n");
		close(listenfd);
		exit(1);
	}
	
	
	for(;;)
	{
		printf("\nSERVER:listening for clients Press ctrl+c to stop echo server\n");
		
		//waiting for message from client
		cli_addr_len=sizeof(cli_addr);
		r=recvfrom(listenfd,buff,128,0,(struct sockaddr*)&cli_addr,&cli_addr_len);
		if(r<0)
		{
			printf("\nSERVER ERROR: Cannot recieve message from client.\n");
			close(listenfd);
			exit(0);
		}
		else
		{
			buff[r]='\0';
			//echo back the message received from client
			if((w=sendto(listenfd,buff,128,0,(struct sockaddr*)&cli_addr,cli_addr_len))<0)
			{
				printf("\nSERVER ERROR: cannot send message to client\n");
			}
			else
			{
				printf("\nSERVER: Echoed back %s to %s .\n",buff,inet_ntoa(cli_addr.sin_addr));
			}
		}
	}
}
	





