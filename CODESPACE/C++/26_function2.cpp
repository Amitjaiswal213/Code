#include<iostream>
using namespace std;

// void changeValue(int z){
//     z=100;
//     //return z;
// }

// int main(){

//     int a=50;
//     changeValue(a);
//     cout<<a<<endl;

//     return 0;
// }


void changeValue(int &z){
    z=100;
    //return z;
}
int main(){

    int a=50;
    changeValue(a);
    cout<<a<<endl;

    return 0;
}