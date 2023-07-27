#include<iostream>
using namespace std;

int fib(int n){

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    //if(n=0 || n=1){
    //    return n;
    //}

    return fib(n-1) + fib(n-2);
}

int main(){

    int n;
    cout<<"Enter n=";
    cin>>n;

    cout<<"Fibonacci= "<<fib(n)<<endl;

    return 0;
}