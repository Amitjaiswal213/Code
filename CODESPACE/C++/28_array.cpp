#include<iostream>
using namespace std;

int main(){

    int array[]={1,2,3,4};

    cout<<sizeof(array)<<endl;
    cout<<endl;

    cout<<sizeof(array)/sizeof(array)[1];
    cout<<endl;

    int size=sizeof(array)/sizeof(array)[1];

    //for loop
    for(int idx=0;idx<size;idx++){
        cout<<array[idx]<<endl;
    }

    cout<<endl;

    //for each loop
    for(int ele:array){
        cout<<ele<<endl;
    }

    cout<<endl;

    //while loop
    int index=1;
    while(index<=size){
        cout<<index<<endl;
        index++;
    }

    return 0;
}