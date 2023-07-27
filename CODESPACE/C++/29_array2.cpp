//Find maximum value in Array
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

    int max=array[0];

    for(int i=1;i<n;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    cout<<endl<<"Maximum Element: "<<max<<endl;

    return 0;
}