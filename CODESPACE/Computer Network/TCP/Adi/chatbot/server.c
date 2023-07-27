#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

struct sockaddr_in serv_addr,cli_addr;
int listenfd, connfd,r,w,cli_addr_len;
unsigned short serv_port = 25005;
char serv_ip[] = "127.0.0.1";
char rbuff[128], sbuff[128];

int main(){
	bzero(&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(serv_port);
	inet_aton(serv_ip,(&serv_addr.sin_addr));
	
	printf("\nServer: ChatBox\n");
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	
	int bi = bind(listenfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	
	int li = listen(listenfd,5);
	
	cli_addr_len = sizeof(cli_addr_len);
	
	for(;;){
		printf("\nServer: listening for Client.... press ctrl+c to stop.\n");
		
		connfd = accept(listenfd,(struct sockaddr *)&cli_addr, &cli_addr_len);
		
		printf("\nServer: Connection from the Client accepted.\n");
		
		while(1){
			bzero(rbuff,128);
			bzero(sbuff,128);
			
			r = read(connfd,rbuff,128);
			rbuff[r] = '\0';
			printf("\nServer: Message from client: %s\n",rbuff);
			if(!strncmp(rbuff,"bye",3))
				break;
			
			fgets(sbuff,128,stdin);
			w = write(connfd,sbuff,128);
			if(!strncmp(sbuff,"bye",3))
				exit(1);
			printf("Server Message sent to client.\n");
		}
		close(connfd);
	}
	return 0;
}