#include<iostream>
using namespace std;

int main(){

int no;
cout<<"Enter the decimal no: ";
cin>>no;

int ans=0;
int power=1;
while(no>0){
    int paritydigit=no%2;
    ans=ans+(paritydigit*power);
    power=power*10;
    no=no/2;
}
cout<<"Binary no are: "<<ans;

    return 0;
}