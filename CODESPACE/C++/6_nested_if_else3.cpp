#include<iostream>
using namespace std;

int main(){

    int marks;
    cout<<"Enter the marks: ";
    cin>>marks;

    if (marks>33){
        if(marks>70){
            cout<<"Pass-(Excellent Marks)";
        }
        else{
        cout<<"Pass-(Good Marks)";
        }
    }
    else
    {
        cout<<"Fail-(Better luck Next Time)";
    }
    cout<<endl;


    cout<<"Enter marks: ";
    cin>>marks;
    marks>33? cout<<"Pass" : cout<<"Fail"; 

    return 0;
}