#include <iostream>

// define nested namespace
namespace MyNamespace {
    namespace SubNamespace {
        int myFunction(int a, int b) {
            return a + b;
        }
    }
}

int main() {
    // call function from nested namespace
    int result = MyNamespace::SubNamespace::myFunction(3, 5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
