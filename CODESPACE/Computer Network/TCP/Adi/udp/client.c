#include<fcntl.h>
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
#include<unistd.h>
 
#include<sys/types.h>
 
#include<sys/socket.h>
 
#include<netinet/in.h>
 
#include<arpa/inet.h>
 
struct sockaddr_in serv_addr;
 
int sockfd,r,w,serv_addr_len;
 
unsigned short serv_port=25071;
 
char serv_ip[]="127.0.0.1";
 
char buff[128];
 
char readbuff[128];
 
int main()
 
{
 
	FILE* ptr;
 
	char reply[128];
 
	bzero(&serv_addr,sizeof(serv_addr));
 
	
 
 
 
	serv_addr.sin_family=AF_INET;
 
	serv_addr.sin_port=htons(serv_port);
 
	inet_aton(serv_ip,(&serv_addr.sin_addr));
 
 
 
	printf("\n UDP ECHO CLIENT.\n");
 
	//Creating Socket
 
	 sockfd=socket(AF_INET,SOCK_DGRAM,0);
 
	if(sockfd<0)
 
	{
 
		printf("\n CLIENT ERROR: Cannot create socket.\n");
 
		exit(1);
 
	}
 
	
 
	printf("\n Connected to Server.\n");
 
	//send message to the echo server
 
	serv_addr_len=sizeof(serv_addr);
 
	for(;;)
 
	{
 
		printf("Enter the Command: \n");
 
		gets(buff);
 
		if(!strcmp("bye",buff))
 
		{
 
			sendto(sockfd,buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
			printf("Exited");
 
			close(sockfd);
 
			break;
 
		}
 
		else
 
		{
 
			sendto(sockfd,buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
		
 
			    // Opening file in reading mode
 
			    //recvfrom(sockfd,readbuff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
			    recvfrom(sockfd,readbuff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
			    recvfrom(sockfd,reply,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
			    if(!strcmp("done",reply))
 
			    {
 
				    
 
				    printf("%s",readbuff);
 
			    }
 
	
 
		}
 
	}
 
	close(sockfd);
 
}
