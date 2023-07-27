#include<fcntl.h>
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
#include<unistd.h>
 
#include<sys/types.h>
 
#include<sys/socket.h>
 
#include<netinet/in.h>
 
#include<arpa/inet.h>
 
#include<time.h>
 
struct sockaddr_in serv_addr;
 
int skfd,r,w,serv_addr_len;
 
unsigned short serv_port=25070;
 
char serv_ip[]="127.0.0.1";
 
char rbuff[128];
 
char sbuff[128];
 
int main()
 
{
 
	bzero(&serv_addr,sizeof(serv_addr));
 
	
 
 
 
	serv_addr.sin_family=AF_INET;
 
	serv_addr.sin_port=htons(serv_port);
 
	inet_aton(serv_ip,(&serv_addr.sin_addr));
 
 
 
	printf("\n UDP ECHO CLIENT.\n");
 
	//Creating Socket
 
	 skfd=socket(AF_INET,SOCK_DGRAM,0);
 
	if(skfd<0)
 
	{
 
		printf("\n CLIENT ERROR: Cannot create socket.\n");
 
		exit(1);
 
	}
 
	
 
	printf("\n Connected to Server.\n");
 
	//send message to the echo server
 
	serv_addr_len=sizeof(serv_addr);
 
	do{
 
		printf("\nCLIENT : ");
 
		gets(sbuff);
 
		w=sendto(skfd,sbuff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
		if(w<0)
 
		{
 
			printf("\n CLIENT ERROR: cannot send message to the echo erver.\n");
 
			close(skfd);
 
			exit(1);
 
		}
 
		if(strcmp(sbuff,"bye")==0)
 
		break;
 
		//printf("\n CLIENT : Message sent to echo server :\n");
 
		//read back the echoed message from server
 
 
 
		r=recvfrom(skfd,rbuff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
		if(r<0)
 
		{
 
			printf("\nCLIENT ERROR: Cannot receive message to server.\n");
 
		}
 
		if(strcmp(rbuff,"bye")==0)
 
		break;
 
		else
 
		{
 
			//rbuff[r]='\0';
 
			printf("\nSERVER Message: %s\n",rbuff);
 
		}
 
	}while(strcmp(sbuff,"bye")!=0);
 
	close(skfd);
 
	exit(1);
 
}
