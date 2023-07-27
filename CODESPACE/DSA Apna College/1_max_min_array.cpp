#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getMin(int a[],int n){
    int res=a[0];
    for(int i=1;i<n;i++)
        res=min(res, a[i]);
    return res;
}

int getMax(int a[],int n){
    int res=a[0];
    for(int i=1;i<n;i++)
        res=max(res,a[i]);
    return res; 
}

int main(){
    //Input Array
    int a[]={1,423,6,46,34,23,13,53,4};
    int n=sizeof(a)/sizeof(a[0]);
    
    //sort(a,a+n);
    //cout<< "min- " << a[0]<<endl<< "max- " << a[n-1] << endl;

    cout<<"minimum element: "<<getMin(a,n)<<endl;
    cout<<"Maximum element: "<<getMax(a,n);
    return 0;
}