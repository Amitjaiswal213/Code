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
