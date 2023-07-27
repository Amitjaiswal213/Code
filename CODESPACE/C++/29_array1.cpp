#include<iostream>
using namespace std;

int main(){

    int n;

    int array[100];

    cout<<"Enter the size of array: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<i<<" element: "; 
        cin>>array[i];
    }

    return 0;
}