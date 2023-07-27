#include<iostream>
using namespace std;

int main(){

    char character;
    cout<<"Enter any Character: ";
    cin>>character;

    switch(character)
    {
        case 'a':
            cout<<"Vowel"<<endl;
            break;

        case 'e':
            cout<<"Vowel"<<endl;
            break;

        case 'i':
            cout<<"Vowel"<<endl;
            break;

        case 'o':
            cout<<"Vowel"<<endl;
            break;

        case 'u':
            cout<<"Vowel"<<endl;
            break;

        default:
            cout<<"Consonant";
    }

    return 0;
}