#include<iostream>
using namespace std;

int main(){

    int a;
    cout<<"Enter the value of a: ";
    cin>>a;

    int b;
    cout<<"Enter the value of b: ";
    cin>>b;

    cout<<"The value of a+b: "<<a+b<<endl;  
    cout<<"The value of a-b: "<<a-b<<endl;
    cout<<"The value of a*b: "<<a*b<<endl;
    cout<<"The value of a/b: "<<a/b<<endl;
    cout<<"The value of a%b: "<<a%b<<endl;

    cout<<endl;

    cout<<"a=b: "<<(a==b)<<endl;
    cout<<"a!=b: "<<(a!=b)<<endl;     //   0=false,  1=True
    cout<<"a>=b: "<<(a>=b)<<endl;
    cout<<"a<=b: "<<(a<=b)<<endl;

    cout<<endl;

    int c=8;
    c+=3;
    cout<<c<<endl;

    int d=6;
    d-=2;
    cout<<d<<endl;


    return 0;
}