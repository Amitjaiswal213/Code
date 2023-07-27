#include <iostream>
using namespace std;

int main(){

    int n;

    cout<<"Enter the no: ";
    cin>>n;

    int reverse;

    while(n>0){
        int lastDigit=n%10;
        reverse=reverse*10+lastDigit;
        n=n/10;
    }

    cout<<"Reverse="<<reverse;
}