1) good morning
*********server**********
 
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
 
int listenfd,connfd,r,w,val,cli_addr_len;
 
unsigned short serv_port=25068;
 
char serv_ip[]="127.0.0.1";
 
char buff[128];
 
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
 
	
 
	
 
	for(;;)
 
	{
 
		printf("\nSERVER:listening for clients Press ctrl+c to stop echo server\n");
 
		
 
		//waiting for message from client
 
		cli_addr_len=sizeof(cli_addr);
 
		r=recvfrom(listenfd,buff,128,0,(struct sockaddr*)&cli_addr,&cli_addr_len);
 
		if(r<0)
 
		{
 
			printf("\nSERVER ERROR: Cannot recieve message from client.\n");
 
			close(listenfd);
 
			exit(0);
 
		}
 
		else
 
		{
 
			buff[r]='\0';
 
			//echo back the message received from client
 
			if((w=sendto(listenfd,buff,128,0,(struct sockaddr*)&cli_addr,cli_addr_len))<0)
 
			{
 
				printf("\nSERVER ERROR: cannot send message to client\n");
 
			}
 
			else
 
			{
 
				printf("\nSERVER: Echoed back %s to %s .\n",buff,inet_ntoa(cli_addr.sin_addr));
 
			}
 
		}
 
	}
 
}
 
	
**************client***************
 
#include<fcntl.h>
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
#include<unistd.h>
 
#include<sys/types.h>
 
#include<sys/socket.h>
 
#include<netinet/in.h>
 
#include<arpa/inet.h>
 
struct sockaddr_in serv_addr;
 
int skfd,r,w,serv_addr_len;
 
unsigned short serv_PORT=25068;
 
char serv_ip[]="127.0.0.1";
 
char rbuff[128];
 
char sbuff[180]="===Good Morning===";
 
int main()
 
{
 
	bzero(&serv_addr,sizeof(serv_addr));
 
	
 
 
 
	serv_addr.sin_family=AF_INET;
 
	serv_addr.sin_port=htons(serv_PORT);
 
	inet_aton(serv_ip,(&serv_addr.sin_addr));
 
 
 
	printf("\n UDP ECHO CLIENT.\n");
 
	//Creating Socket
 
	 skfd=socket(AF_INET,SOCK_DGRAM,0);
 
	if(skfd<0)
 
	{
 
		printf("\n CLIENT ERROR: Cannot create socket.\n");
 
		exit(1);
 
	}
 
	
 
	printf("\n Connected to Server.\n");
 
	//send message to the echo server
 
	serv_addr_len=sizeof(serv_addr);
 
	w=sendto(skfd,sbuff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
	if(w<0)
 
	{
 
		printf("\n CLIENT ERROR: cannot send message to the echo erver.\n");
 
		close(skfd);
 
		exit(1);
 
	}
 
 
 
	printf("\n CLIENT : Message sent to echo server :\n");
 
	//read back the echoed message from server
 
	
 
	 r=recvfrom(skfd,rbuff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
	if(r<0)
 
	{
 
		printf("\nCLIENT ERROR: Cannot receive message to server.\n");
 
	}
 
	else
 
	{
 
		rbuff[r]='\0';
 
		printf("\nCLIENT:Message from echo server %s\n",rbuff);
 
	}
 
	close(skfd);
 
	exit(1);
 
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
2) chatbot
 
************server*************
 
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
 
int listenfd,connfd,r,w,val,cli_addr_len;
 
unsigned short serv_port=25070;
 
char serv_ip[]="127.0.0.1";
 
char sbuff[128];
 
char rbuff[128];
 
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
 
	for(;;)
 
	{
 
		printf("\nSERVER:listening for clients Press ctrl+c to stop echo server\n");
 
		//accept client connection
 
		
 
	do{
 
		r=recvfrom(listenfd,rbuff,128,0,(struct sockaddr*)&cli_addr,&cli_addr_len);
 
		if(r<0)
 
		{
 
			printf("\nSERVER ERROR: Cannot recieve message from client.\n");
 
		}
 
		if(strcmp(rbuff,"bye")==0)
 
		break;
 
		else
 
		{
 
			//echo back the message received from client
 
			printf("\nCLIENT MESSAGE : %s\n",rbuff);
 
			printf("\nSERVER : ");
 
			gets(sbuff);
 
			if((w=sendto(listenfd,sbuff,128,0,(struct sockaddr*)&cli_addr,cli_addr_len))<0)
 
			{
 
				printf("\nSERVER ERROR: cannot send message to client\n");
 
				exit(1);
 
			}
 
			if(strcmp(sbuff,"bye")==0)
 
			break;
 
		}
 
	}while(1);
 
	}
 
	close(listenfd);
 
	return 0;
 
}	
 
**************client**********************************
 
#include<fcntl.h>
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
#include<unistd.h>
 
#include<sys/types.h>
 
#include<sys/socket.h>
 
#include<netinet/in.h>
 
#include<arpa/inet.h>
 
struct sockaddr_in serv_addr;
 
int skfd,r,w,serv_addr_len;
 
unsigned short serv_port=25070;
 
char serv_ip[]="127.0.0.1";
 
char rbuff[128];
 
char sbuff[128];
 
int main()
 
{
 
	bzero(&serv_addr,sizeof(serv_addr));
 
	
 
 
 
	serv_addr.sin_family=AF_INET;
 
	serv_addr.sin_port=htons(serv_port);
 
	inet_aton(serv_ip,(&serv_addr.sin_addr));
 
 
 
	printf("\n UDP ECHO CLIENT.\n");
 
	//Creating Socket
 
	 skfd=socket(AF_INET,SOCK_DGRAM,0);
 
	if(skfd<0)
 
	{
 
		printf("\n CLIENT ERROR: Cannot create socket.\n");
 
		exit(1);
 
	}
 
	
 
	printf("\n Connected to Server.\n");
 
	//send message to the echo server
 
	serv_addr_len=sizeof(serv_addr);
 
	do{
 
		printf("\nCLIENT : ");
 
		gets(sbuff);
 
		w=sendto(skfd,sbuff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
		if(w<0)
 
		{
 
			printf("\n CLIENT ERROR: cannot send message to the echo erver.\n");
 
			close(skfd);
 
			exit(1);
 
		}
 
		if(strcmp(sbuff,"bye")==0)
 
		break;
 
		//printf("\n CLIENT : Message sent to echo server :\n");
 
		//read back the echoed message from server
 
 
 
		r=recvfrom(skfd,rbuff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
		if(r<0)
 
		{
 
			printf("\nCLIENT ERROR: Cannot receive message to server.\n");
 
		}
 
		if(strcmp(rbuff,"bye")==0)
 
		break;
 
		else
 
		{
 
			//rbuff[r]='\0';
 
			printf("\nSERVER Message: %s\n",rbuff);
 
		}
 
	}while(strcmp(sbuff,"bye")!=0);
 
	close(skfd);
 
	exit(1);
 
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
3) calculator
 
**************************server*****************************
 
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
 
int listenfd,connfd,r,w,val,cli_addr_len,n, len,i,sum;
 
unsigned short serv_port=25071;
 
char serv_ip[]="127.0.0.1";
 
char sbuff[128];
 
char rbuff[128];
 
char buff[128];
 
char operator,c;
 
    float op1;
 
    float op2;
 
    float result=0;
 
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
 
	for(;;)
 
	{
 
		//printf("%d\n",connfd);
 
		
 
		r=recvfrom(listenfd,buff,128,0,(struct sockaddr*)&cli_addr,&cli_addr_len);	
 
		
 
		//taking first operand
 
		len = strlen(buff);
 
		//printf("\n%d\n",len);
 
		i=0,result = 0,n=0,sum=0;
 
		printf("The full expression is: %s\n",buff);
 
		
 
		while(i<len)
 
		{
 
			c=buff[i];
 
			if((c<48)||(c>57))
 
				break;
 
			n = c-'0';	  	//parsing string into int
 
			//printf("%d ",n);
 
			sum = n + sum*10;
 
			i++;
 
		}
 
		result = sum;
 
		operator = buff[i];	//storing operator
 
		//printf("\nThe Operator is: %c\n",operator);
 
		op1=sum;
 
		
 
		
 
		//if((i+1)<len && ((buff[i+1]<48)||(buff[i+1]>57)))
 
		//{
 
		//	write(connfd, "INVALID EXPRESSION", 128);
 
		//	break;
 
		//}
 
 
 
		//printf("\n%c\n",opr);
 
		op2 = 0, n=0,sum=0;
 
		//EXTRACTIONG CHARACTER AFTER OPERATOR
 
		i++;
 
		
 
		//printf("dattebayo %c\n",buff[i]);
 
		while(i<len)
 
		{
 
			c = buff[i];
 
			//printf("dattebayo2\n");
 
			if((c<48)||(c>57))
 
				break;
 
			n = c-'0';
 
			//printf("%d ",n);
 
			sum = n+sum*10;
 
			i++;
 
		}
 
		op2 = sum;
 
		
 
		//read(connfd, &op2, sizeof(op2));	//
 
		printf("op1 value: %f",op1);
 
		printf("op2 value: %f",op2);			
 
		switch (operator)
 
		{
 
		case '+':
 
			result = result + op2;
 
			printf("Result is: %f + %f = %f\n", op1, op2, result);
 
			break;
 
		case '-':
 
			result = result - op2;
 
			printf("Result is: %f - %f = %f\n", op1, op2, result);
 
			break;
 
		case '/':
 
			result = result / op2;
 
			printf("Result is: %f * %f = %f\n", op1, op2, result);
 
			break;
 
		case '*':
 
			result =result * op2;
 
			printf("Result is: %f / %f = %f\n", op1, op2, result);
 
			break;
 
		default:
 
			printf("ERROR: Unsupported Operation");
 
		}
 
 
 
		w=sendto(listenfd,&result,128,0,(struct sockaddr*)&cli_addr,cli_addr_len);
 
	}
 
	close(listenfd);
 
	return 0;
 
}	
 
***********************client*********************
 
#include<fcntl.h>
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
#include<unistd.h>
 
#include<sys/types.h>
 
#include<sys/socket.h>
 
#include<netinet/in.h>
 
#include<arpa/inet.h>
 
struct sockaddr_in serv_addr;
 
int skfd,r,w,serv_addr_len;
 
unsigned short serv_port=25071;
 
char serv_ip[]="127.0.0.1";
 
char rbuff[128];
 
char sbuff[128];
 
char buff[128];
 
int main()
 
{
 
	bzero(&serv_addr,sizeof(serv_addr));
 
	float result=0;
 
 
 
	serv_addr.sin_family=AF_INET;
 
	serv_addr.sin_port=htons(serv_port);
 
	inet_aton(serv_ip,(&serv_addr.sin_addr));
 
 
 
	printf("\n UDP ECHO CLIENT.\n");
 
	//Creating Socket
 
	 skfd=socket(AF_INET,SOCK_DGRAM,0);
 
	if(skfd<0)
 
	{
 
		printf("\n CLIENT ERROR: Cannot create socket.\n");
 
		exit(1);
 
	}
 
	
 
	printf("\n Connected to Server.\n");
 
	//send message to the echo server
 
	serv_addr_len=sizeof(serv_addr);
 
	for(;;)
 
	{
 
		//printf("Enter operation:\n +:Addition \n -: Subtraction \n /: Division \n *:Multiplication \n");
 
		//scanf("%d",1);
 
		//printf("\t");
 
		//scanf("%c", &operator);
 
		printf("Enter the Expression: \n");
 
		gets(buff);
 
		if(strcmp(buff,"bye")==0){exit(1);}
 
		
 
		w=sendto(skfd,buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
		if(result==0)
 
		{
 
			
 
		}
 
		//write(sockfd, &op2, sizeof(op2));
 
		r=recvfrom(skfd,&result,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
		printf("Operation result from server=%f\n", result);
 
	}
 
	close(skfd);
 
	exit(1);
 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
4) time
 
************************server*****************
 
#include<fcntl.h>
 
#include<unistd.h>
 
#include<sys/socket.h>
 
#include<sys/types.h>
 
#include<netinet/in.h>
 
#include<arpa/inet.h>
 
#include<string.h>
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<time.h>
 
struct sockaddr_in serv_addr,cli_addr;
 
int listenfd,connfd,r,w,val,cli_addr_len;
 
unsigned short serv_port=25070;
 
char serv_ip[]="127.0.0.1";
 
char sbuff[128];
 
char rbuff[128];
 
int main()
 
{
 
	time_t t=time(NULL);
 
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
 
	for(;;)
 
	{
 
		printf("\nSERVER:listening for clients Press ctrl+c to stop echo server\n");
 
		//accept client connection
 
		
 
	do{
 
		
 
		r=recvfrom(listenfd,rbuff,128,0,(struct sockaddr*)&cli_addr,&cli_addr_len);
 
		
 
		if(r<0)
 
		{
 
			printf("\nSERVER ERROR: Cannot recieve message from client.\n");
 
		}
 
		if(strcmp(rbuff,"bye")==0)
 
		break;
 
		else
 
		{
 
			//echo back the message received from client
 
			printf("\nCLIENT MESSAGE : %s\n",rbuff);
 
			//time struct variable
 
			struct tm tm= *localtime(&t);
 
			printf("\nSERVER : %02d:%02d:%02d",tm.tm_hour,tm.tm_min,tm.tm_sec);
 
			if(tm.tm_hour < 12)
 
			{
 
				printf("\nSERVER :Good morning\n");
 
					strcpy(sbuff,"Good morning");
 
			}
 
			if(tm.tm_hour >12 && tm.tm_hour < 16)
 
			{
 
				printf("\nSERVER :Good Afternoon\n");
 
				strcpy(sbuff,"Good AfterNoon");
 
			}
 
			if(tm.tm_hour >16)
 
			{
 
				printf("\nSERVER :Good evening\n");
 
					strcpy(sbuff,"Good evening");
 
			}
 
			if((w=sendto(listenfd,sbuff,128,0,(struct sockaddr*)&cli_addr,cli_addr_len))<0)
 
			{
 
				printf("\nSERVER ERROR: cannot send message to client\n");
 
				exit(1);
 
			}
 
			if(strcmp(sbuff,"bye")==0)
 
			break;
 
		}
 
	}while(1);
 
	}
 
	close(listenfd);
 
	return 0;
 
}	
 
*******************************client*******************
 
#include<fcntl.h>
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
#include<unistd.h>
 
#include<sys/types.h>
 
#include<sys/socket.h>
 
#include<netinet/in.h>
 
#include<arpa/inet.h>
 
#include<time.h>
 
struct sockaddr_in serv_addr;
 
int skfd,r,w,serv_addr_len;
 
unsigned short serv_port=25070;
 
char serv_ip[]="127.0.0.1";
 
char rbuff[128];
 
char sbuff[128];
 
int main()
 
{
 
	bzero(&serv_addr,sizeof(serv_addr));
 
	
 
 
 
	serv_addr.sin_family=AF_INET;
 
	serv_addr.sin_port=htons(serv_port);
 
	inet_aton(serv_ip,(&serv_addr.sin_addr));
 
 
 
	printf("\n UDP ECHO CLIENT.\n");
 
	//Creating Socket
 
	 skfd=socket(AF_INET,SOCK_DGRAM,0);
 
	if(skfd<0)
 
	{
 
		printf("\n CLIENT ERROR: Cannot create socket.\n");
 
		exit(1);
 
	}
 
	
 
	printf("\n Connected to Server.\n");
 
	//send message to the echo server
 
	serv_addr_len=sizeof(serv_addr);
 
	do{
 
		printf("\nCLIENT : ");
 
		gets(sbuff);
 
		w=sendto(skfd,sbuff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
		if(w<0)
 
		{
 
			printf("\n CLIENT ERROR: cannot send message to the echo erver.\n");
 
			close(skfd);
 
			exit(1);
 
		}
 
		if(strcmp(sbuff,"bye")==0)
 
		break;
 
		//printf("\n CLIENT : Message sent to echo server :\n");
 
		//read back the echoed message from server
 
 
 
		r=recvfrom(skfd,rbuff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
		if(r<0)
 
		{
 
			printf("\nCLIENT ERROR: Cannot receive message to server.\n");
 
		}
 
		if(strcmp(rbuff,"bye")==0)
 
		break;
 
		else
 
		{
 
			//rbuff[r]='\0';
 
			printf("\nSERVER Message: %s\n",rbuff);
 
		}
 
	}while(strcmp(sbuff,"bye")!=0);
 
	close(skfd);
 
	exit(1);
 
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
5) shell command
 
****************server*******************
 
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
 
int listenfd,connfd,r,w,val,cli_addr_len;
 
unsigned short serv_port=25070;
 
char serv_ip[]="127.0.0.1";
 
char sbuff[128];
 
char rbuff[128];
 
char read_buff[128],write_buff[128];
 
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
 
	for(;;)
 
	{
 
		
 
		//printf("\nconnected to the client.. ready to chat.. ip :: %s\n",inet_ntoa(cli_addr.sin_addr));
 
		for(;;)
 
		{
 
		
 
			int readStatus=recvfrom(listenfd,read_buff,128,0,(struct sockaddr*)&cli_addr,&cli_addr_len);
 
			if(readStatus<0)
 
			{
 
				printf("\ncan not read from the client\n");
 
			}
 
			else
 
			{
 
				printf("cli :: %s\n",read_buff);
 
				if (!strcmp("bye", read_buff))
 
    		{
 
    		    printf("The Client ended\n");
 
    		    break;
 
    		    //write(connfd, reply, 128);
 
    		}
 
				printf("\ngenerating the command\n");
 
				char fileDir[]=" > temp";
 
				strcat(read_buff,fileDir);
 
				//printf("\n%s\n",read_buff);
 
				if(system(read_buff)!=0)
 
				{
 
					system("echo 'invalid command' > temp");
 
				}
 
				//system("cat temp");
 
			
 
			}
 
			
 
			FILE *file=fopen("temp","r");
 
			if(file== NULL)
 
			{
 
				printf("\nerror in opening file\n");
 
				exit(1);
 
			}
 
			while(!feof(file))
 
			{
 
				fgets(write_buff,128,file);
 
				if(feof(file))
 
					break;
 
			//	printf("\nprinting :: %s\n",write_buff);
 
				int writeStatus=sendto(listenfd,write_buff,128,0,(struct sockaddr*)&cli_addr,cli_addr_len);
 
				if(writeStatus<0)
 
				{
 
					printf("\ncan not write\n");
 
					exit(0);
 
				}
 
				
 
			}
 
			fclose(file);
 
			char exitMsg[]="XXXXXXXX";
 
			sendto(listenfd,exitMsg,128,0,(struct sockaddr*)&cli_addr,cli_addr_len);
 
			
 
			
 
		}
 
	
 
	}
 
	close(listenfd);
 
	return 0;
 
}	
 
*****************************client*************************
 
#include<fcntl.h>
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
#include<unistd.h>
 
#include<sys/types.h>
 
#include<sys/socket.h>
 
#include<netinet/in.h>
 
#include<arpa/inet.h>
 
struct sockaddr_in serv_addr;
 
int skfd,r,w,serv_addr_len;
 
unsigned short serv_port=25070;
 
char serv_ip[]="127.0.0.1";
 
char rbuff[128];
 
char read_buff[128],write_buff[128];
 
char sbuff[128];
 
int main()
 
{
 
	bzero(&serv_addr,sizeof(serv_addr));
 
	
 
 
 
	serv_addr.sin_family=AF_INET;
 
	serv_addr.sin_port=htons(serv_port);
 
	inet_aton(serv_ip,(&serv_addr.sin_addr));
 
 
 
	printf("\n UDP ECHO CLIENT.\n");
 
	//Creating Socket
 
	 skfd=socket(AF_INET,SOCK_DGRAM,0);
 
	if(skfd<0)
 
	{
 
		printf("\n CLIENT ERROR: Cannot create socket.\n");
 
		exit(1);
 
	}
 
	
 
	printf("\n Connected to Server.\n");
 
	//send message to the echo server
 
	serv_addr_len=sizeof(serv_addr);
 
	while(1){
 
		printf("cli :: ");
 
		gets(write_buff);
 
		if(!strcmp("bye",write_buff))
 
    		{
 
    			sendto(skfd,write_buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
    			
 
    			printf("Exited\n");
 
    			close(skfd);
 
    			break;
 
    		}
 
		int writeStatus=sendto(skfd,write_buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
		if(writeStatus<0)
 
		{
 
			printf("\ncan not write to the client\n");
 
		}
 
	
 
		sleep(1);
 
	
 
		while(1)
 
		{
 
			int readStatus=recvfrom(skfd,read_buff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
			if(readStatus<0)
 
			{
 
				printf("\ncan not read\n");
 
			}
 
			else{
 
				read_buff[readStatus]='\0';
 
				char exitMsg[]="XXXXXXXX";
 
				if(strcmp(read_buff,exitMsg)==0)
 
					break;
 
				else
 
					printf("\n%s\n",read_buff);
 
			}
 
		}
 
		
 
	}
 
	close(skfd);
 
	exit(1);
 
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
6) file 
 
********************server*****************
 
#include <sys/types.h>
 
    #include <sys/socket.h>
 
    #include <stdio.h>
 
    #include <netinet/in.h>
 
    #include <unistd.h>
 
    #include <string.h>
 
    #include <arpa/inet.h>
 
    #include <stdlib.h>
 
	#include<fcntl.h>
 
     
 
    char buff[128];
 
    char reply[128];
 
    char readbuff[10000];
 
    char readingBuff[10000];
 
    char fileName[128];
 
    char ch;
 
    FILE *ptr;
 
     
 
    void main()
 
    {
 
        int b, sockfd, connfd, sin_size, l, n, len, i, sum,clientaddr_len;
 
        char operator, c;
 
        float op1;
 
        float op2;
 
        float result = 0;
 
        if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) > 0)
 
            printf("socket created sucessfully\n"); //socket creation
 
        //printf("%d\n", sockfd);                 //on success 0 otherwise -1
 
     
 
        struct sockaddr_in servaddr;
 
        struct sockaddr_in clientaddr;
 
     
 
        servaddr.sin_family = AF_INET;
 
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
        servaddr.sin_port = 25024;
 
     
 
        if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) == 0)
 
            printf("bind sucessful\n");
 
     
 
     
 
     printf("accept sucessful\n");
 
        for (;;)
 
        {
 
    	
 
    	   //sin_size = sizeof(struct sockaddr_in);
 
            
 
		clientaddr_len=sizeof(clientaddr);
 
        	for(;;)
 
        	{
 
        	
 
     
 
    		recvfrom(sockfd, buff, 128,0,(struct sockaddr*)&clientaddr,&clientaddr_len); 
 
    		printf("\n client:%s\n",buff);
 
    		if (!strcmp("bye", buff))
 
    		{
 
    		    printf("The Client ended\n");
 
    		    break;
 
    		    //write(connfd, reply, 128);
 
    		}
 
    		else
 
    		{
 
     
 
    		    char cmdBuff[128] = "ls ";
 
    		    //adding *into the keyword
 
    		    strcat(buff,"*");
 
    		    
 
    		    strcat(cmdBuff, buff);
 
    		    strcat(cmdBuff,">file1.txt");
 
    		    system(cmdBuff);
 
     
 
    		    ptr = fopen("file1.txt", "r");
 
    			
 
    			if(fgetc(ptr)==EOF)
 
    			{
 
    				printf("\nNo Such File Exists\n");
 
    				sendto(sockfd, "NoSuchFile", 128,0,(struct sockaddr*)&clientaddr,clientaddr_len);
 
    			}
 
    			else{
 
    				rewind(ptr);
 
				bzero(readbuff,128);
 
    				int i = 0;
 
    				while ((ch = fgetc(ptr)) != EOF)
 
    				{
 
    					readbuff[i] = ch;
 
    					i++;
 
    				 }
 
    				    fclose(ptr);
 
    				    sendto(sockfd, readbuff, 128,0,(struct sockaddr*)&clientaddr,clientaddr_len);
 
    				    sendto(sockfd, "readDone", 128,0,(struct sockaddr*)&clientaddr,clientaddr_len);
 
    				    
 
    				    //Takeing File name and reading it
 
				for(;;)
 
				{
 
    				    recvfrom(sockfd,fileName,128,0,(struct sockaddr*)&clientaddr,&clientaddr_len);
 
    				    printf("\n client:%s\n",fileName);
 
    				    ptr = fopen(fileName,"r");
 
    				   if(ptr==NULL)
 
    				   {
 
					char wrongFile[128]="wrongfile";
 
					printf("WRONG FILE\n");
 
    				   	sendto(sockfd, wrongFile, 10000,0,(struct sockaddr*)&clientaddr,clientaddr_len);
 
    				   }
 
    				   else{
 
    					int j = 0;
 
					bzero(readingBuff,10000);
 
    					while ((ch = fgetc(ptr)) != EOF)
 
    					{
 
    						readingBuff[j] = ch;
 
    						j++;
 
    					 }
 
    					 fclose(ptr);
 
    					 sendto(sockfd,readingBuff,10000,0,(struct sockaddr*)&clientaddr,clientaddr_len);
 
    					 sendto(sockfd,"fileReadDone",128,0,(struct sockaddr*)&clientaddr,clientaddr_len);	
 
					 bzero(readingBuff,10000);
 
					//readingBuff[0]='\0';
 
					break;			    
 
    				   }
 
    		    
 
    				}
 
				}			
 
    		}
 
    		buff[0] = '\0';
 
    		}
 
        }
 
        close(sockfd);
 
    }
 
***********************client************************
 
#include <sys/types.h>
 
    #include <sys/socket.h>
 
    #include <stdio.h>
 
    #include <netinet/in.h>
 
    #include <unistd.h>
 
    #include <string.h>
 
    #include <strings.h>
 
    #include <arpa/inet.h>
 
    #include <stdlib.h>
 
     	#include<fcntl.h>
 
     
 
     
 
    char buff[128];
 
    char readbuff[128];
 
    char fileName[128];
 
    char fileContain[10000];
 
    char replyAfter[128];
 
     
 
    void main()
 
    {
 
        int b, sockfd, sin_size, con, n, len,servaddr_len;
 
        char operator;
 
        float op1;
 
        float op2;
 
        float result=0;
 
        float op3=0;
 
        char ch;
 
    	FILE* ptr;
 
    	char reply[128];
 
        
 
        if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) > 0)
 
            printf("socket created sucessfully\n");
 
        //printf("%d\n", sockfd);
 
        struct sockaddr_in servaddr;
 
     
 
        servaddr.sin_family = AF_INET;
 
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
        servaddr.sin_port = 25024;
 
    	
 
    	//sin_size = sizeof(struct sockaddr_in);
 
    	
 
    	for(;;)
 
    	{
 
		servaddr_len=sizeof(servaddr);
 
    		printf("Enter the Keyword: \n");
 
    		gets(buff);
 
 
 
    		if(!strcmp("bye",buff))
 
    		{
 
    			sendto(sockfd,buff,128,0,(struct sockaddr*)&servaddr,servaddr_len);
 
    			//printf("\nChal Nikal PahleFursat Mai\n");
 
    			printf("Exited\n");
 
    			close(sockfd);
 
    			break;
 
    		}
 
    		else
 
    		{
 
    			sendto(sockfd, buff, 128,0,(struct sockaddr*)&servaddr,servaddr_len);
 
    			    // Opening file in reading mode
 
    			    recvfrom(sockfd, readbuff, 128,0,(struct sockaddr*)&servaddr,&servaddr_len);
 
    			    if(strcmp("NoSuchFile",readbuff)==0)
 
    			    {
 
    			    		printf("No Such File Exists\n");
 
    			    		//printf("Aisa Kiasa chalega re koi file'e nhi hai (￣_￣)\n");//No Such File Exists
 
    			    }
 
    			    else{			    
 
    				    recvfrom(sockfd,reply,128,0,(struct sockaddr*)&servaddr,&servaddr_len);
 
    				    if(!strcmp("readDone",reply))
 
    				    {
 
    					    printf("%s",readbuff);
 
    				    }
 
				for(;;)
 
				{
 
    				    printf("\nEnter which file you want to Open: \n\n");
 
    				    gets(fileName);
 
    				    sendto(sockfd,fileName,128,0,(struct sockaddr*)&servaddr,servaddr_len);
 
					
 
					bzero(fileContain,10000);
 
    				    recvfrom(sockfd,fileContain,10000,0,(struct sockaddr*)&servaddr,&servaddr_len);
 
					//printf("%s\n",fileContain);
 
 
 
    				    if(!strcmp("wrongfile",fileContain))
 
    				    {
 
						printf("\nYou Entered Wrong Name\n");
 
    				    }
 
    				    else{
 
    					    recvfrom(sockfd,replyAfter,128,0,(struct sockaddr*)&servaddr,&servaddr_len);
 
    					     if(!strcmp("fileReadDone",replyAfter))
 
    					    {
 
    						    printf("%s\n",fileContain);
 
    				    		}
 
						bzero(fileContain,10000);
 
						break;
 
    				    }
 
				}
 
    			    }
 
		bzero(readbuff,128);
 
    		}
 
    	}
 
    	close(sockfd);
 
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
7) binary calculator
 
*******************server**********************
 
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
 
******************client***********************
 
#include<fcntl.h>
 
#include<stdio.h>
 
#include<stdlib.h>
 
#include<string.h>
 
#include<unistd.h>
 
#include<sys/types.h>
 
#include<sys/socket.h>
 
#include<netinet/in.h>
 
#include<arpa/inet.h>
 
struct sockaddr_in serv_addr;
 
int sockfd,r,w,serv_addr_len;
 
unsigned short serv_port=25071;
 
char serv_ip[]="127.0.0.1";
 
char buff[128];
 
char readbuff[128];
 
int main()
 
{
 
	FILE* ptr;
 
	char reply[128];
 
	bzero(&serv_addr,sizeof(serv_addr));
 
	
 
 
 
	serv_addr.sin_family=AF_INET;
 
	serv_addr.sin_port=htons(serv_port);
 
	inet_aton(serv_ip,(&serv_addr.sin_addr));
 
 
 
	printf("\n UDP ECHO CLIENT.\n");
 
	//Creating Socket
 
	 sockfd=socket(AF_INET,SOCK_DGRAM,0);
 
	if(sockfd<0)
 
	{
 
		printf("\n CLIENT ERROR: Cannot create socket.\n");
 
		exit(1);
 
	}
 
	
 
	printf("\n Connected to Server.\n");
 
	//send message to the echo server
 
	serv_addr_len=sizeof(serv_addr);
 
	for(;;)
 
	{
 
		printf("Enter the Command: \n");
 
		gets(buff);
 
		if(!strcmp("bye",buff))
 
		{
 
			sendto(sockfd,buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
			printf("Exited");
 
			close(sockfd);
 
			break;
 
		}
 
		else
 
		{
 
			sendto(sockfd,buff,128,0,(struct sockaddr*)&serv_addr,serv_addr_len);
 
		
 
			    // Opening file in reading mode
 
			    //recvfrom(sockfd,readbuff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
			    recvfrom(sockfd,readbuff,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
			    recvfrom(sockfd,reply,128,0,(struct sockaddr*)&serv_addr,&serv_addr_len);
 
			    if(!strcmp("done",reply))
 
			    {
 
				    
 
				    printf("%s",readbuff);
 
			    }
 
	
 
		}
 
	}
 
	close(sockfd);
 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////