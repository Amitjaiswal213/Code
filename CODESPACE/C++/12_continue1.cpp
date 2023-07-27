//Print all the value b/w 1 to 50 except the multiple of 3.

#include<iostream>
using namespace std;

int main(){

int i=1;

while(i<=50){
    i++;
    if(i%3==0){
        continue;
    }
    cout<<i<<endl;
}
    return 0;
}


// for(int i=1;i<=50;i++){
//         if(i%3==0){
//             continue;
//         }
//         cout<<i<<endl;
//     }