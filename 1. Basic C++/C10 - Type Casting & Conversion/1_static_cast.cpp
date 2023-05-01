#include <iostream>

using namespace std;

int main() {
    double x = 3.14;
    int y = static_cast<int>(x);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}

/**
 * In this example, we are converting a double value x to an integer y using static_cast.
 * The result is that the decimal portion of x is truncated and y is assigned the integer value 3. 
 **/
void NOTE(){};