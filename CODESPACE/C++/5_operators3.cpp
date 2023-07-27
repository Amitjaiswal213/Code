#include<iostream>
using namespace std;

int main(){

    cout<<"FOR THE VALUE OF 'a'--"<<endl;

    int a;
    cout<<"Enter the no: ";
    cin>>a;

    cout<<-(~a)<<endl;    
    cout<<(a<<1)<<endl;   
    cout<<(a>>1)<<endl;

    cout<<"FOR THE VALUE OF 'b'--"<<endl;

    int b;
    cout<<"Enter the no: ";
    cin>>b;

    cout<<~b<<endl;
    cout<<(b<<1)<<endl;
    cout<<(b>>1)<<endl;

    return 0;
}