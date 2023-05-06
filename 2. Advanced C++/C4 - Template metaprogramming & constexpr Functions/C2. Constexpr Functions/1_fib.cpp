#include <iostream>

constexpr int fib(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}


int main() {
    
    // Using static_assert to check if the function is working properly
    static_assert(fib(10) == 55, "fib(10) should be 55");
    static_assert(fib(20) == 6765, "fib(20) should be 6765");
    
    return 0;
}
