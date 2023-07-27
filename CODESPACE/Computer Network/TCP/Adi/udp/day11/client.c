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
 
unsigned short serv_port=25070;
 
char serv_ip[]="127.0.0.1";
 
char rbuff[128];
 
char read_buff[128],write_buff[128];
 
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
 
	while(1){
 
		printf("cli :: ");
 
		gets(write_buff);
 
		if(!strcmp("bye",write_buff))
 
    		{
 
    			sendto(skfd,write_buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
    			
 
    			printf("Exited\n");
 
    			close(skfd);
 
    			break;
 
    		}
 
		int writeStatus=sendto(skfd,write_buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
		if(writeStatus<0)
 
		{
 
			printf("\ncan not write to the client\n");
 
		}
 
	
 
		sleep(1);
 
	
 
		while(1)
 
		{
 
			int readStatus=recvfrom(skfd,read_buff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
			if(readStatus<0)
 
			{
 
				printf("\ncan not read\n");
 
			}
 
			else{
 
				read_buff[readStatus]='\0';
 
				char exitMsg[]="XXXXXXXX";
 
				if(strcmp(read_buff,exitMsg)==0)
 
					break;
 
				else
 
					printf("\n%s\n",read_buff);
 
			}
 
		}
 
		
 
	}
 
	close(skfd);
 
	exit(1);
 
}
