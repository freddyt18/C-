#include <iostream>
#define SQUARE(x) ((x) * (x))

int main() {
    int a = 5;
    std::cout << "Square of " << a << " is " << SQUARE(a) << std::endl;
    return 0;
}


/**
 * In this example, the SQUARE macro takes an argument x and expands to ((x) * (x)). 
 * The macro is used to calculate the square of an integer variable a.
 */
void NOTE(){};