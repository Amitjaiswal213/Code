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
 
int listenfd,connfd,r,w,val,cli_addr_len,sin_size;
 
unsigned short serv_port=25071;
 
char serv_ip[]="127.0.0.1";
 
char buff[128];
 
char reply[128];
 
char readbuff[128];
 
char ch;
 
FILE *ptr;
 
 
 
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
 
	for (;;)
 
    {
 
	
 
	
 
	   sin_size = sizeof(struct sockaddr_in);
 
        printf("accept sucessful\n");
 
    	for(;;)
 
    	{
 
    	
 
 
 
		recvfrom(listenfd,buff,128,0,(struct sockaddr*)&cli_addr,&cli_addr_len);
 
		printf("\n client:%s\n",buff);
 
		if (!strcmp("bye", buff))
 
		{
 
		    printf("The Client ended\n");
 
		    break;
 
		    //write(connfd, reply, 128);
 
		}
 
		else
 
		{
 
 
 
		    char str[128] = "echo ";
 
		    strcat(buff, " | bc>file2.txt");
 
		    strcat(str, buff);
 
		    system(str);
 
 
 
		    ptr = fopen("file2.txt", "r");
 
 
 
		    int i = 0;
 
		    int x=0;
 
		    while ((ch = fgetc(ptr)) != EOF)
 
		    {
 
		        readbuff[i] = ch;
 
		        i++;
 
		        x++;
 
		    }
 
		    if(x==0)
 
		    {
 
		    	sendto(listenfd, "cant divide by 0\n", 128,0,(struct sockaddr*)&cli_addr,cli_addr_len);	
 
		    }
 
		    else
 
		    sendto(listenfd,readbuff,128,0,(struct sockaddr*)&cli_addr,cli_addr_len);
 
		    sendto(listenfd, "done", 128,0,(struct sockaddr*)&cli_addr,cli_addr_len);
 
		}
 
		buff[0] = '\0';
 
		}
 
    }
 
	close(listenfd);
 
	return 0;
 
}	
 
