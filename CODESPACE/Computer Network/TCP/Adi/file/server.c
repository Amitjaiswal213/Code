#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

struct sockaddr_in serv_addr,cli_addr;
int listenfd,connfd,r,w,cli_addr_len;
unsigned short serv_port = 28000;
char serv_ip[] = "127.0.0.1";
char rbuff[2048],sbuff[2048],temp[2048],script[2048];
FILE* f;

int main(){
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serv_port);
    inet_aton(serv_ip,(&serv_addr.sin_addr));

    listenfd = socket(AF_INET,SOCK_STREAM,0);

    int bi = bind(listenfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

    int li = listen(listenfd,0);

    cli_addr_len = sizeof(cli_addr);
    for(;;){
        printf("\nServer: Waiting for client .....\n");

        connfd = accept(listenfd,(struct sockaddr *)&cli_addr,&cli_addr_len);

        printf("\nServer: Litening for clients\n");

        while(1){
            bzero(rbuff,2048);
            bzero(sbuff,2048);
            bzero(temp,2048);
            bzero(script,2048);

            r = read(connfd,rbuff,2048);
            printf("\nServer: character from Client : %s\n",rbuff);
            if(!strncmp(rbuff,"bye",3))
                break;
            strcat(script,"ls -d ");
            strcat(script,rbuff);
            strcat(script,"* >abc");
            system(script);
            f = fopen("abc","r");
            while(fgets(temp,2048,f) != NULL)
                strcat(sbuff,temp);

            w = write(connfd,sbuff,2048);
            printf("\nserver: filename sent to client.\n");

            if(sbuff[0] != '\0'){
                bzero(rbuff,2048);
                bzero(sbuff,2048);
                bzero(temp,2048);
                bzero(script,2048);

                while(sbuff[0] == '\0'){
                    r = read(connfd,rbuff,2048);
                    printf("Server: Filename from client: %s\n",rbuff);
                    if(!strncmp(rbuff,"bye",3))
                        break;
                    strcat(script,"cat ");
                    strcat(script,rbuff);
                    strcat(script,"> pqr");
                    system(script);
                    f = fopen("pqr","r");
                    while(fgets(temp,2048,f) != NULL)
                        strcat(sbuff,temp);

                    w = write(connfd,sbuff,2048);
                    printf("Server: content of file sent to client.\n");
                }
            }
        }
    }
    return 0;
}