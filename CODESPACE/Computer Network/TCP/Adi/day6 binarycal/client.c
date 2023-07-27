  #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<unistd.h>
    #include<sys/socket.h>
    #include<sys/types.h>
    #include<netinet/in.h>
    #include<arpa/inet.h>
     
    struct sockaddr_in serv_addr;
    unsigned short serv_port=25031;
    char serv_ip[]="127.0.0.1";
    char bye[]="bye";
    char exitMsg[]="XXXXXXXX";
    char read_buff[128],write_buff[128];
     
    int main()
    {
    	bzero(&serv_addr,sizeof(serv_addr));
    	serv_addr.sin_family=AF_INET;
    	serv_addr.sin_port=htons(serv_port);
    	inet_aton(serv_ip,(&serv_addr.sin_addr));
    	
    	printf("\nTCP client Echo\n");
    	
    	int sockfd=socket(AF_INET,SOCK_STREAM,0);
    	if(sockfd<0)
    	{
    		printf("\ncan not create socket\n");
    		exit(0);
    	}
    	printf("\nsocket created\n");
    	
    	int connfd=connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    	if(connfd<0)
    	{
    		printf("\ncan not connect to the server\n");
    		close(sockfd);
    		exit(0);
    	}
    	printf("\nconnected to the server.. ready to chat\n");
    	while(1){
    		printf("expression :: ");
    		gets(write_buff);
    		printf("\n%s\n",write_buff);
    		if(strcmp(write_buff,bye)==0)
    		{
    			int writeStatus=write(sockfd,write_buff,128);
    			printf("\ndisconnecting from server\n");
    			exit(0);
    		}
    		int writeStatus=write(sockfd,write_buff,128);
    		if(writeStatus<0)
    		{
    			printf("\ncan not write to the client\n");
    		}
    	
    		sleep(1);
    	
    		while(1)
    		{
    			int readStatus=read(sockfd,read_buff,128);
    			if(readStatus<0)
    			{
    			
    				printf("\ncan not read from the client\n");
    			}
    			else
    			{
    				read_buff[readStatus]='\0';
    				if(strcmp(read_buff,exitMsg)==0)
    				{
    					break;
    				}
    			
    				printf("result of the expression :: %s\n",read_buff);	
    			}
    		}
    		
    	}
    	close(sockfd);
    	return 0;
    }
