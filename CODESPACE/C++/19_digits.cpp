#include <iostream>
using namespace std;

int main(){

    int n;

    cout<<"Enter the digits: ";
    cin>>n;

    int digits=0;

    while(n>0){
        digits++;
        n=n/10;
    }
    cout<<"Total no of digits= "<<digits;
}