#include <iostream>

// define namespace
namespace MyNamespace {
    int myFunction(int a, int b) {
        return a + b;
    }
}

// alias namespace
namespace MN = MyNamespace;

int main() {
    // call function using alias namespace
    int result = MN::myFunction(3, 5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
