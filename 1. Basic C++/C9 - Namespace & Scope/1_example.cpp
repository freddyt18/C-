#include <iostream>

// define namespace
namespace MyNamespace {
    int myFunction(int a, int b) {
        return a + b;
    }
}

int main() {
    // call function from namespace
    int result = MyNamespace::myFunction(3, 5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
