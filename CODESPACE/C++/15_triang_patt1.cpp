#include<iostream>
using namespace std;

int main(){

    int n;

    cout<<"Enter the no of Rows: ";
    cin>>n;

    // cout<<"Enter the no of Columns: ";
    // cin>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
    

    return 0;
}