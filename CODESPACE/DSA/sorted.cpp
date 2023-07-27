#include<iostream>
using namespace std;

bool sorted(int arr[], int n){

    if(n==1){
        return true;
    }

    bool restArray = sorted(arr+1, n-1);
    return (arr[0]<arr[1] && restArray);

}

int main(){

    int arr[]={2,4,5,7,8,9};

    cout<<sorted(arr,6)<<endl;

    return 0;
}