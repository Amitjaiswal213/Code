void mergeSort(int a[],int lb,int ub);
void merge(int a[],int lb,int mid,int ub);
int BinarySearch(int a[],int key,int n);
int c[100];
int main(){
	
	int a[100];
	int n,key;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the elements of the array\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Sorted form of the given array is:\n");
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\nEnter the search key element of the array: ");
	scanf("%d",&key);
	if(BinarySearch(a,key,n)==-1)
		printf("%d not found in the array",key);
	else
		printf("%d found at position %d in the sorted array",key,BinarySearch(a,key,n));
	return 0;
}
void mergeSort(int a[],int lb,int ub){
	int mid;
	if(lb<ub){
		mid=(lb+ub)/2;
		mergeSort(a,lb,mid);
		mergeSort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}
void merge(int a[],int lb,int mid,int ub){
	int i,j,k;
	i=lb,j=mid+1;
	k=lb;
	while(i<=mid && j<=ub){
		if(a[i]<=a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}
	for(;i<=mid;i++)
		c[k++]=a[i];
	for(;j<=ub;j++)
		c[k++]=a[j];
	for(int m=lb;m<=ub;m++)
	    a[m]=c[m];
}
int BinarySearch(int a[],int key,int n){
	int lb=0,ub=n-1;
	int mid=(lb+ub)/2;
	while(lb<=ub){
		if(a[mid]==key)
		return mid;
		if(a[mid]>key)
		ub=mid-1;
		else
		lb=mid+1;
		mid=(lb+ub)/2;
	}
	return -1;
}