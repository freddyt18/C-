#include <iostream>


constexpr int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(){

    // Using static_assert to check if the function is working properly
    static_assert(factorial(0) == 1);
    static_assert(factorial(1) == 1);
    static_assert(factorial(5) == 120);
    static_assert(factorial(10) == 3628800);

    // This will fail since the factorial of 5 is equal to 120
    // Uncomment the line below to see the error
    // static_assert(factorial(5) == 1, "factorial(5) should be 120");


    return 0;
}