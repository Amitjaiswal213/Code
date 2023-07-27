#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

struct sockaddr_in serv_addr,cli_addr;
int skfd,r,w,serv_addr_len;
unsigned short serv_port = 25005;
char serv_ip[] = "127.0.0.1";
char rbuff[128],sbuff[128];

int main(){
	bzero(&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(serv_port);
	inet_aton(serv_ip,(&serv_addr.sin_addr));
	
	printf("\nClient : ChatBox\n");
	
	skfd = socket(AF_INET,SOCK_STREAM,0);
	
	int co = connect(skfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	
	printf("\nClient: Connected to the server.\n");
	
	while(1){
		bzero(rbuff,128);
		bzero(sbuff,128);
		fgets(sbuff,128,stdin);
		w = write(skfd,sbuff,128);
		if(!strncmp(sbuff,"bye",3))
			break;
			
		r = read(skfd,rbuff,128);
		rbuff[r] = '\0';
		if(!strncmp(rbuff,"bye",3))
			break;
		printf("\nClient: Message from server :  %s\n",rbuff);
	}
}