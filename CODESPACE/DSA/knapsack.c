#include<stdio.h>
void knapsack(float *arr,int capacity,int *wgt,int *pft,int n)
{
    float x[n];
    float sum=0.0;
    int i;
    for(int i=0;i<n;i++)
    {
        x[i]=0.0;
    }
    int U=capacity;
    for(i=0;i<n;i++)
    {
        if(wgt[i]>U)
        {
            break;
        }
        x[i]=1.0;
        U-=wgt[i];
    }
    if(i<=n)
    {
        x[i]=(float)U/wgt[i];
    }
    for(int i=0;i<n;i++)
    {
        sum+=pft[i]*x[i];
    }
    printf("Total sum is %f",sum);
}
int main()
{
    int capacity,n;
    printf("Enter the no of objects:");
    scanf("%d",&n);
    int pft[n];
    int wgt[n];
    //float *p;
    float ratio[n];
    printf("Enter the capacity:");
    scanf("%d",&capacity);
    printf("Enter the profit of all elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pft[i]);
    }
    printf("Enter the weight of all elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&wgt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ratio[i]=(float)pft[i]/wgt[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                int temp;
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                temp=wgt[i];
                wgt[i]=wgt[j];
                wgt[j]=temp;

                temp=pft[i];
                pft[i]=pft[j];
                pft[j]=temp;
            }
        }
    }

    knapsack(ratio,capacity,wgt,pft,n);
    return 0;
}