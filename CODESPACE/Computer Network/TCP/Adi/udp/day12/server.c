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
