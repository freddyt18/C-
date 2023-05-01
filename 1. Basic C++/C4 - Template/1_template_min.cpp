#include <iostream>

template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}

int main() {

    int a = 5, b = 3;
    float c = 2.5, d = 3.7;
    
    std::cout 
        << "Minimum of " << a << " and " << b 
        << " is " << minimum(a, b) 
        << std::endl;
    std::cout 
        << "Minimum of " << c 
        << " and " << d 
        << " is " << minimum(c, d) 
        << std::endl;
    
    return 0;
}
