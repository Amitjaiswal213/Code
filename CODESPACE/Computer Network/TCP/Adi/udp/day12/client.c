 
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
