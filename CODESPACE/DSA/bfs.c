#include<stdio.h>
#define MAX 10
int adj[MAX][MAX],visit[MAX]={0};
int queue[MAX],front=-1,rear=-1;
void enqueue(int n)
{
	if(rear==MAX-1)
		printf("Overflow\n");
	else
		queue[++rear]=n;
}
int dequeue()
{
	if(front==rear)
		printf("Underflow\n");
	else
		return queue[++front];
	return -1;
}
int isempty()
{
	if(front==rear)
		return 1;
	else
		return 0;
}
void BFS(int u,int n)
{
	int i=u,j;
	printf("%d ",i);
	visit[i]=1;
	enqueue(i);
	
	while(!isempty())
	{
		i=dequeue();
		for(j=1;j<n;j++)
		{
			if(adj[i][j]==1 && visit[j]==0)
			{
				printf("%d ",j);
				visit[j]=1;
				enqueue(j);
			}
		}
	}
	for(int i=1; i<n;i++)
	{
	    if(visit[i]==0)
	        BFS(i,n);
	}
	
}
int main()
{
	int v,i,j,root;
    printf("Enter the no. of vertices in graph:");
    scanf("%d",&v);                                                               //0 1 1 0 0 0 0
                                                                                  //0 0 0 1 0 0 0
    printf("\nEnter the values in form of adjacent matrix:\n");                   //0 0 0 1 0 0 0
    for(i=1;i<v+1;i++)                                                            //0 0 0 0 0 0 0
    {                                                                             //0 0 0 0 0 1 1
        for(j=1;j<v+1;j++)                                                        //0 0 0 0 0 0 1
        {                                                                         //0 0 0 0 0 0 0
            
            scanf("%d",&adj[i][j]);
        }
    }
    /*for(i=1;i<v+1;i++)
    {
        for(j=1;j<v+1;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }*/
	printf("Enter the root for BFS: "); 
	scanf("%d",&root);  
	BFS(root,v+1);
	return 0;			
}