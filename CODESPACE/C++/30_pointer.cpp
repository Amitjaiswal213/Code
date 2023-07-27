#include<iostream>
using namespace std;

int main(){

    int a=10;
    int *aptr;                          // *-- Deference operator
    aptr=&a;                            // &-- Address of operator

    cout<<*aptr<<endl;

    aptr++;
    cout<<*aptr<<endl;

    return 0;
}
