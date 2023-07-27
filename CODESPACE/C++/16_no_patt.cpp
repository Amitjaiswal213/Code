#include<iostream>
using namespace std;

int main(){

    int n,m;

    cout<<"Enter the no of Rows: ";
    cin>>n;

    // cout<<"Enter the no of Columns: ";
    // cin>>m;
    
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cout<<j;
        }
        for(int j=1;j<=(i-1);j++){
            cout<<j;
        }
        cout<<endl;    
    }

    return 0;
}