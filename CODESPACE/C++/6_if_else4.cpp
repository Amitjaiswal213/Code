//Write a program to print the value if it is Even and divisible by 3.

#include<iostream>
using namespace std;

int main(){

    int num;
    cout<<"Enter the num: ";
    cin>>num;

    if (num%2==0){
        if (num%3==0){
            cout<<"Even and Divisible by 3";
        }
        else{
            cout<<"Even and not Divisible by 3";
        }
    }
    else
    {
        cout<<"Odd";
    }
    

    return 0;
}