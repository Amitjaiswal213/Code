#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>

struct sockaddr_in serv_addr,cli_addr;
int skfd,r,w,serv_addr_len;
unsigned short serv_port = 28000;
char serv_ip[] = "127.0.0.1";
char rbuff[2048],sbuff[2048];

int main(){
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serv_port);
    inet_aton(serv_ip,(&serv_addr.sin_addr));

    skfd = socket(AF_INET,SOCK_STREAM,0);

    int co = connect(skfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

    while(1){
        bzero(rbuff,2048);
        bzero(sbuff,2048);

        printf("\nEnter Character: \n");
        gets(sbuff);
        w = write(skfd,sbuff,2048);
        printf("\nClient: character send to server\n");
        if(!strncmp(sbuff,"bye",3))
            exit(1);

        r = read(skfd,rbuff,2048);
        printf("\nClient: filename from server: %s\n",rbuff);

        if(rbuff[0] != '\0'){
            bzero(rbuff,2048);
            bzero(sbuff,2048);

            while(rbuff[0] == '\0'){
                printf("\nEnter Filename: \n");
                gets(sbuff);
                w = write(skfd,sbuff,2048);
                printf("\nClient: Filename sent to server.\n");
                if(!strncmp(sbuff,"bye",3))
                    exit(1);

                r = read(skfd,rbuff,2048);
                printf("Client: Message from server: %s\n",rbuff);
            }
        }
    }
    return 0;
}