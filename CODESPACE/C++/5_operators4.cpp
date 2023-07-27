#include<iostream>
using namespace std;

int main(){

    int a;
    cout<<"Enter the a: ";
    cin>>a;

    int b;
    cout<<"Enter the b: ";
    cin>>b;

    cout<<(a&b)<<endl;          //gives value in true or false
    cout<<(a|b)<<endl;
    cout<<(a^b)<<endl;

    cout<<sizeof(a)<<endl;      //gives size of a
    cout<<sizeof(b)<<endl;

    cout<<&a<<endl;                 //gives address of a
    cout<<&b<<endl;

    char name='a';

    cout<<sizeof(name)<<endl;  

    bool aj;

    a==5? aj=true : aj=false;
    cout<<aj<<endl;

    return 0;
}