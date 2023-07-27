#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<fcntl.h>

#include<unistd.h>

#include<sys/socket.h>

#include<sys/types.h>

#include<arpa/inet.h>



struct sockaddr_in serv_addr,cli_addr;

int listenfd,connfd,r,w,cli_addr_len;

unsigned short serv_port = 25010;

char serv_ip[] = "127.0.0.1";

char rbuff[128],sbuff[128],temp[128],script[128];

FILE* f;



int main(){

	bzero(&serv_addr,sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;

	serv_addr.sin_port = htons(serv_port);

	inet_aton(serv_ip,(&serv_addr.sin_addr));

	

	listenfd = socket(AF_INET,SOCK_STREAM,0);

	

	int bi = bind(listenfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

	

	int li = listen(listenfd,5);

	

	cli_addr_len = sizeof(cli_addr);

	for(;;){

		printf("\nServer: Listening to clients ..... press ctrl+c to stop.\n");

		

		connfd = accept(listenfd,(struct sockaddr *)&cli_addr, &cli_addr_len);

		

		printf("\nServer: connection from client accepted.\n");

		

		while(1){

			bzero(rbuff,128);

			bzero(sbuff,128);

			bzero(temp,128);

			bzero(script,128);

			

			r = read(connfd,rbuff,128);

			printf("\nServer : message from client : %s\n",rbuff);

			if(!strncmp(rbuff,"bye",3))

				break;

			strcat(script,"echo \"scale=2; ");

			strcat(script,rbuff);

			strcat(script,"\" | bc -l");

			strcat(script," > xyz");

			system(script);

			f = fopen("xyz","r");

			while(fgets(temp,128,f) != NULL){

				strcat(sbuff,temp);

			}

			

			//fgets(sbuff,128,stdin);

			w = write(connfd,sbuff,128);

			if(!strncmp(sbuff,"bye",3))

				exit(1);

			printf("\nServer: Message send to client.\n");

		}

		close(connfd);

	}

	return 0;

}