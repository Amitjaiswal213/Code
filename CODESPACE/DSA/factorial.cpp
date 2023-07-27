#include<iostream>
using namespace std;

int Factorial(int n){

    if(n==0){
        return 1;
    }

    int prevFactorial= Factorial(n-1);
    return n*prevFactorial;
}

int main(){

    int n;
    cin>>n;

    cout<<"Factorial="<<Factorial(n)<<endl;

    return 0;
}