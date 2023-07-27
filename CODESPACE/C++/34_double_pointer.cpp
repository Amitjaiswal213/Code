#include<iostream>
using namespace std;

void increment1(int **p){
    p=p+1;
}

void increment1(int **p){
    *p=*p+1;
}

void increment1(int **p){
    **p=**p+1;
}

int main(){

int i=10;
int * p1 = &i;
int ** p2 = &p1;

cout<<p1<< endl;
cout<<p2<<endl;

cout<<endl;

cout<<*p1<<endl;
cout<<*p2<<endl;
cout<<**p2<<endl;

cout<<endl;

cout<<i<<endl;
cout<<&i<<endl;


}