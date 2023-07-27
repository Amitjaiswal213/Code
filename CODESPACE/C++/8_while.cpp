//Print the sum of first N Natural number.

#include<iostream>
using namespace std;

int main(){

int n;
int i=1;
int sum=0;

cout<<"Enter the num: ";
cin>>n;

while (i<=n)
{
    sum+=i;
    i++;
}
cout<<sum;

    return 0;
}