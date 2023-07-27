#include<iostream>
using namespace std;

int main(){

    int age;
    cout<<"Enter the age: ";
    cin>>age;

    if (age <= 12)
    {
        cout<<"Child";
    }
    else if (age>12 && age<=18)
    {
        cout<<"Teenager";
    }
    else if(age>18 && age<120)
    {
        cout<<"Adult";
    }
    else
    {
        cout<<"Mrr gya Madharchod";
    }
    

    return 0;
}