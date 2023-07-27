#include<iostream>
using namespace std;

int main(){

int num1,num2,num3;

cout<<"-----Enter Three Number-----"<<endl;
cout<<"Num1: ";
cin>>num1;

cout<<"num2: ";
cin>>num2;

cout<<"num3: ";
cin>>num3;

if(num1>num2){
    if(num1>num3){
        cout<<"Max: "<<num1<<endl;
    }else{
        cout<<"Max: "<<num3<<endl;
    }
}
else{
    if(num2>num3){
        cout<<"max: "<<num2;
    }
    else{
        cout<<"Max: "<<num3;
    }
}

    return 0;
}