#include <iostream>

namespace MyNamespace {
    int x = 10;
}

int main() {
    using namespace MyNamespace;
    
    std::cout << "The value of x is: " << x << std::endl;
    
    return 0;
}
