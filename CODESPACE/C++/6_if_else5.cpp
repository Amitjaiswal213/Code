//write a program to print a number which is divisuble by 3 or 5.

#include<iostream>
using namespace std;

int main(){

    int num;
    cout<<"Enter a num: ";
    cin>>num;

    if((num%3==0) || (num%5==0)){
        if(num%3==0){
            cout<<"Divisible by 3"<<endl;
        }
        if (num%5==0)
        {
            cout<<"Divisible by 5";
        }
    }
    else{
        cout<<"Not Divisible by 3 or 5";
    }
    

    return 0;
}