#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>

struct sockaddr_in serv_addr,cli_addr;
int skfd,r,w,serv_addr_len;
unsigned short serv_port = 25020;
char serv_ip[] = "127.0.0.1";
char rbuff[2048],sbuff[2048];

int main(){
	bzero(&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(serv_port);
	inet_aton(serv_ip,(&serv_addr.sin_addr));
	
	skfd = socket(AF_INET,SOCK_STREAM,0);
	
	printf("\nClient : SHELL COMMAND\n");
	
	int co = connect(skfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	
	printf("\nClient: Connected to server.\n");
	
	while(1){
		bzero(rbuff,2048);
		bzero(sbuff,2048);
		
		// fgets(sbuff,2048,stdin);
		// scanf("%s",sbuff);
		gets(sbuff);
		w = write(skfd,sbuff,2048);
		if(!strncmp(sbuff,"bye",3))
			break;
		printf("\nClient: Message sent to Client.\n");
		
		r = read(skfd,rbuff,2048);
		printf("\nClient: Message from Server: %s\n",rbuff);
	}
	return 0;
}