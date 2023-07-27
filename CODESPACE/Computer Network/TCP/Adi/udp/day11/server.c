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
 
unsigned short serv_port=25070;
 
char serv_ip[]="127.0.0.1";
 
char sbuff[128];
 
char rbuff[128];
 
char read_buff[128],write_buff[128];
 
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
 
	
 
	cli_addr_len=sizeof(cli_addr);
 
	for(;;)
 
	{
 
		
 
		//printf("\nconnected to the client.. ready to chat.. ip :: %s\n",inet_ntoa(cli_addr.sin_addr));
 
		for(;;)
 
		{
 
		
 
			int readStatus=recvfrom(listenfd,read_buff,128,0,(struct sockaddr*)&cli_addr,&cli_addr_len);
 
			if(readStatus<0)
 
			{
 
				printf("\ncan not read from the client\n");
 
			}
 
			else
 
			{
 
				printf("cli :: %s\n",read_buff);
 
				if (!strcmp("bye", read_buff))
 
    		{
 
    		    printf("The Client ended\n");
 
    		    break;
 
    		    //write(connfd, reply, 128);
 
    		}
 
				printf("\ngenerating the command\n");
 
				char fileDir[]=" > temp";
 
				strcat(read_buff,fileDir);
 
				//printf("\n%s\n",read_buff);
 
				if(system(read_buff)!=0)
 
				{
 
					system("echo 'invalid command' > temp");
 
				}
 
				//system("cat temp");
 
			
 
			}
 
			
 
			FILE *file=fopen("temp","r");
 
			if(file== NULL)
 
			{
 
				printf("\nerror in opening file\n");
 
				exit(1);
 
			}
 
			while(!feof(file))
 
			{
 
				fgets(write_buff,128,file);
 
				if(feof(file))
 
					break;
 
			//	printf("\nprinting :: %s\n",write_buff);
 
				int writeStatus=sendto(listenfd,write_buff,128,0,(struct sockaddr*)&cli_addr,cli_addr_len);
 
				if(writeStatus<0)
 
				{
 
					printf("\ncan not write\n");
 
					exit(0);
 
				}
 
				
 
			}
 
			fclose(file);
 
			char exitMsg[]="XXXXXXXX";
 
			sendto(listenfd,exitMsg,128,0,(struct sockaddr*)&cli_addr,cli_addr_len);
 
			
 
			
 
		}
 
	
 
	}
 
	close(listenfd);
 
	return 0;
 
}	
 
