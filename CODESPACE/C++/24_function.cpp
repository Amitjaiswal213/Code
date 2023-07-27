#include<iostream>
using namespace std;

int sum(int x, int y){
    int sum=x+y;
    return sum;
}
    
int main(){

    int x,y;

    cout<<"Enter x= ";
    cin>>x;
    

    cout<<"Enter y= ";
    cin>>y;
    
    cout<<sum(x,y)<<endl;

    return 0;
}