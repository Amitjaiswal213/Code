#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<time.h>

struct sockaddr_in serv_addr,cli_addr;
int listenfd,connfd,r,w,cli_addr_len;
unsigned short serv_port = 25015;
char serv_ip[] = "127.0.0.1";
char rbuff[128],sbuff[128],temp[128],script[128],wish[128];
long int t,c;
float hr;

int main(){
	bzero(&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(serv_port);
	inet_aton(serv_ip,(&serv_addr.sin_addr));
	
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	
	int bi = bind(listenfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	
	int li = listen(listenfd,5);
	
	printf("\nServer: TIME AND DATE\n");
	
	cli_addr_len = sizeof(cli_addr);
	
	for(;;){
		printf("\nListening to client ..... press ctrl+c to stop.\n");
		
		connfd = accept(listenfd,(struct sockaddr *)&cli_addr, &cli_addr_len);
		
		printf("\nServer: Connection from Client Accepted.\n");
		
		
		bzero(rbuff,128);
		bzero(sbuff,128);
		bzero(temp,128);
		bzero(script,128);
		bzero(&t,sizeof(t));
		
		r = read(connfd,rbuff,128);
		printf("\nServer: Message from client : %s\n",rbuff);
		for(int i = 0; i < strlen(rbuff); i++){
			if(rbuff[i] == ':'){
				c = i;
				break;
			}
		}
		wish[0] = rbuff[c-2];
		wish[1] = rbuff[c-1];
		hr = atof(wish);
		if(hr > 0 && hr < 12)
			printf("\nGood Morning Server.\n");
		else if(hr > 12 && hr < 17)
			printf("\nGood afternoon Server.\n");
		else if(hr > 17 && hr < 22)
			printf("\nGood Evening Server.\n");
		else
			printf("\nGood Night Server.\n");
		
		t = time(NULL);
		strcpy(sbuff,ctime(&t));
		w = write(connfd,sbuff,128);
		printf("\nServer: Message sent to client.\n");
		
		close(connfd);
	}
	return 0;
}