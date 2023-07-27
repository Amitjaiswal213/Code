#include<iostream>
using namespace std;

int main(){

    int a;
    cout<<"Enter the value of a: ";
    cin>>a;
    
    int b;
    cout<<"Enter the value of b: ";
    cin>>b;
    cout<<endl;

   // int temp;

    int temp=a;
    a=b;
    b=temp;

    cout<<"AFTER SWAPPING"<<endl<<endl;

    cout<<"The value of a: "<<a<<endl;
    cout<<"The value of b: "<<b<<endl;
    


    return 0;
}