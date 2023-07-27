#include <iostream>
using namespace std;
 
// Following function that takes two parameters 'x' and 'y'
// as input and returns max of two input numbers
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
 
// main function that doesn't receive any parameter and
// returns integer
int main()
{
    int a,b;

    cout<<"Enter the value of a: ";
    cin>>a;

    cout<<"Enter the value of b: ";
    cin>>b;
 
    // Calling above function to find max of 'a' and 'b'
    int m = max(a, b);
 
    cout << "max is " << m;
    return 0;
}
