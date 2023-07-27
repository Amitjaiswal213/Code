#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<time.h>

struct sockaddr_in serv_addr,cli_addr;
int skfd,r,w,serv_addr_len;
unsigned short serv_port = 25015;
char serv_ip[] = "127.0.0.1";
char rbuff[128],sbuff[128],wish[128];
long int t,c;
float hr;

int main(){
	bzero(&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(serv_port);
	inet_aton(serv_ip,(&serv_addr.sin_addr));
	
	skfd = socket(AF_INET,SOCK_STREAM,0);
	
	printf("\nClient : DATE AND TIME\n");
	
	int co = connect(skfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	
	printf("\nClient: Connected to server.\n");
	
	
	bzero(rbuff,128);
	bzero(sbuff,128);
	bzero(&t,sizeof(t));
	t = time(NULL);
	strcpy(sbuff,ctime(&t));
	w = write(skfd,sbuff,128);
		
	r = read(skfd,rbuff,128);
	printf("\nClient : Message from server: %s\n",rbuff);
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
		printf("\nGood Morning client.\n");
	else if(hr > 12 && hr < 17)
		printf("\nGood afternoon client.\n");
	else if(hr > 17 && hr < 22)
		printf("\nGood Evening client.\n");
	else
		printf("\nGood Night client.\n");
	
	
	return 0;
}