#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

struct sockaddr_in serv_addr,cli_addr;
int listenfd,connfd,r,w,cli_addr_len;
unsigned short serv_port = 25020;
char serv_ip[] = "127.0.0.1";
char rbuff[2048],sbuff[2048],temp[128],script[2048];
FILE* f;

int main(){
	bzero(&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(serv_port);
	inet_aton(serv_ip,(&serv_addr.sin_addr));
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	
	int bi = bind(listenfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	
	int li = listen(listenfd,5);
	
	printf("\nServer: SHELL COMMAND\n");
	
	cli_addr_len = sizeof(cli_addr);
	
	for(;;){
		printf("\nServer: Listening to Client...... press ctrl+c to stop.\n");
		
		connfd = accept(listenfd,(struct sockaddr *)&cli_addr,&cli_addr_len);
		
		printf("\nServer : Connection from client Accepted.\n");
		while(1){
			bzero(rbuff,2048);
			bzero(sbuff,2048);
			bzero(temp,128);
			bzero(script,2048);
			
			r = read(connfd,rbuff,2048);
			rbuff[r] = '\0';
			printf("\nServer: Command from Client %s\n",rbuff);
			if(!strncmp(rbuff,"bye",3))
				break;
			strcat(rbuff, ">abc");
			system(rbuff);

			f = fopen("abc", "r");
			while(fgets(temp, 128, f) != NULL)
				strcat(sbuff,temp);
			
			w = write(connfd,sbuff,2048);
			printf("\nServer: Message sent to Client.\n");
		}
		close(connfd);
	}
}