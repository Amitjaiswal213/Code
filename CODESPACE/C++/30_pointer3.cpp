#include<iostream>
using namespace std;

int main(){
    int i=10;
    cout<<i<<endl;
    cout<<&i<<endl;

    int *p=&i;
    cout<<p<<endl;
    cout<<*p <<endl;
    cout<<endl; 

    cout<< sizeof(p)<<endl;
    cout<< sizeof(*p)<<endl;

    i++;

    cout<<endl;

    cout<< i <<endl;
    cout<< *p <<endl;

    cout<<endl;

    int a=*p;
    a++;
    cout<<a<<endl;
    cout<<*p<<endl;

}