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
 
int skfd,r,w,serv_addr_len;
 
unsigned short serv_port=25071;
 
char serv_ip[]="127.0.0.1";
 
char rbuff[128];
 
char sbuff[128];
 
char buff[128];
 
int main()
 
{
 
	bzero(&serv_addr,sizeof(serv_addr));
 
	float result=0;
 
 
 
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
 
	for(;;)
 
	{
 
		//printf("Enter operation:\n +:Addition \n -: Subtraction \n /: Division \n *:Multiplication \n");
 
		//scanf("%d",1);
 
		//printf("\t");
 
		//scanf("%c", &operator);
 
		printf("Enter the Expression: \n");
 
		gets(buff);
 
		if(strcmp(buff,"bye")==0){exit(1);}
 
		
 
		w=sendto(skfd,buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
		if(result==0)
 
		{
 
			
 
		}
 
		//write(sockfd, &op2, sizeof(op2));
 
		r=recvfrom(skfd,&result,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
		printf("Operation result from server=%f\n", result);
 
	}
 
	close(skfd);
 
	exit(1);
 
}
