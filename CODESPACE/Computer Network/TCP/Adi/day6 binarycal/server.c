    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<unistd.h>
    #include<sys/socket.h>
    #include<sys/types.h>
    #include<netinet/in.h>
    #include<arpa/inet.h>
     
    struct sockaddr_in serv_addr,cli_addr;
    int connfd,writeStatus;
    unsigned short serv_port=25031;
    char serv_ip[]="127.0.0.1";
     
    char read_buff[128],write_buff[128];
    char bye[]="bye";
    char exitMsg[]="XXXXXXXX";
char mess[]="Can't divide by zero";
     
    int main()
    {
    	bzero(&serv_addr,sizeof(serv_addr));
    	serv_addr.sin_family=AF_INET;
    	serv_addr.sin_port=htons(serv_port);
    	inet_aton(serv_ip,(&serv_addr.sin_addr));
    	
    	printf("\nTCP Echo Sever \n");
    	
    	int sockfd=socket(AF_INET,SOCK_STREAM,0);
    	if(sockfd<0)
    	{
    		printf("\ncan not create socket\n");
    		exit(0);
    	}
    	printf("\nsocket created successfully\n");
    	
    	int bindStatus=bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    	if(bindStatus<0)
    	{
    		printf("\ncan not bind\n");
    		close(sockfd);
    		exit(0);
    	}
    	printf("\nbinded successfully\n");
    	
    	int listenStstus=listen(sockfd,5);
    	if(listenStstus<0)
    	{
    		printf("\n server is not searching the client\n");
    		close(sockfd);
    		exit(0);
    	}
    	printf("\nserver is searching for the clients\n");
    	int cli_addr_len=sizeof(cli_addr);
    	for(;;)
    	{
    		connfd=accept(sockfd,(struct sockaddr*)&cli_addr,&cli_addr_len);
    		if(connfd<0)
    		{
    			printf("\ncan not connect to the client\n");
    			close(sockfd);
    			exit(0);
    		}
    		printf("\nconnected to the client.. ready to chat.. ip :: %s\n",inet_ntoa(cli_addr.sin_addr));
    		for(;;)
    		{
    		
    			int readStatus=read(connfd,read_buff,128);
    			if(readStatus<0)
    			{
    				printf("\ncan not read from the client\n");
    			}
    			else
    			{
    				if(strcmp(read_buff,bye)==0)
    				{
    					printf("cli :: %s\n",read_buff);
    					printf("disconnectiong from client..\n");
    					close(connfd);
    					break;
    				}
    				//read_buff[readStatus]='\0';
    				printf("cli :: %s\n",read_buff);
    				printf("\nsending the result\n");
    				char echoDir[]="echo '";
    				char fileDir[]="' | bc > temp";
    				strcat(read_buff,fileDir);
    				strcat(echoDir,read_buff);
    				if(system(echoDir)!=0)
    				{
    					system("echo 'invalid expression' > temp");
    				}
    				
    				FILE *file=fopen("temp","r");
    				if(file== NULL)
    				{
    					printf("\nerror in opening file\n");
    					exit(1);
    				}
				int x=1;
    				while(!feof(file))
    				{
					
    					fgets(write_buff,128,file);
    					if(feof(file))
    						break;
					x=0;
    					 writeStatus=write(connfd,write_buff,128);
    					if(writeStatus<0)
    					{
    						printf("\ncan not write\n");
    						exit(0);
    					}
    					
    				}
    				fclose(file);
				if(x)
					{
						write(connfd,mess,128);
					}
    				write(connfd,exitMsg,128);
    			
    			}
    			
    		
    		}
    	
    	}
     
    	return 0;
    }
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
  
