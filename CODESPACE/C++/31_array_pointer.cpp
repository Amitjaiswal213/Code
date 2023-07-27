#include<iostream>
using namespace std;

int main(){

int a[10];
cout << a << endl;
cout <<&a<<endl;
cout <<a[0]<<endl;
cout <<&a[0]<<endl;
cout <<a[1]<<endl;
cout <<&a[1]<<endl;
cout <<a[2]<<endl;
cout<<endl;

a[0]=5;
cout<<*a<<endl;
cout<<a+1<<endl;
cout <<*(a+1)<<endl;
cout<<a<<endl;
cout<<*a<<endl;

}