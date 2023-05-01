#include <iostream>
#include <iomanip>

int main() {
    int x = 123;
    double y = 3.14159;

    // Using printf()
    printf("x = %d, y = %.2f\n", x, y);

    // Using stream manipulators
    std::cout 
        << std::setw(5) 
        << std::setfill('0') 
        << x 
        << std::endl;

    std::cout 
        << std::setprecision(3) 
        << std::fixed 
        << y 
        << std::endl;

    return 0;
}
