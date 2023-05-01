#include <iostream>

using namespace std;

int main() {
    const int x = 5;
    int& y = const_cast<int&>(x);
    y = 10;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}


/**
 * In this example, we have a const integer x and we want to modify its value.
 * 
 * We use const_cast to remove the const qualifier from x and create a reference y that can be used to modify the value of x. 
 * 
 * After assigning a new value to y, we print out both x and y to show that they have the same value. 
 * 
 * Note that modifying a const object like this is generally not recommended and can lead to unexpected behavior.
 */
void NOTE(){};