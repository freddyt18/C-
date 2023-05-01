#include <iostream>
using namespace std;

int main() {

    int myInt_1 = 1;
    int myInt_2 = 2;

    float myFloat_1 = 2.123;
    float myFloat_2 = 3.14;
    
    // If-else statement
    if ( myFloat_1 > myFloat_2 ) {
        cout << myFloat_1 << " is bigger than " << myFloat_2 << endl;
    
    } else {
        cout << myFloat_2 << " is smaller than " << myFloat_2 << endl;
    
    };


    // Ternary operator
    ( myInt_1 > myInt_2 ) ?
        cout << myInt_1 << " is bigger than " << myInt_2 << endl :
        cout << myInt_1 << " is smaller than " << myInt_2 << endl << endl;


    // For loop
    for (int i = 0; i <= 2; i++) {
        ( i <= 1 ) ? 
            cout << i << " is smaller or equal to 1" << endl :
            cout << i << " is bigger equal than 1" << endl;
    }

    return 0;

}