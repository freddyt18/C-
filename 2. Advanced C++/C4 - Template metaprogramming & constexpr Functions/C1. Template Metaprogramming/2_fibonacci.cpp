#include <iostream>


// Fibonacci is a sequence of numbers where each number is the sum of the two preceding ones, starting from 0 and 1.

// Fibonacci of 5 is 5, because 5 = 3 + 2, 3 = 2 + 1, 2 = 1 + 1, 1 = 1 + 0

template <int N>
struct Fibonacci{
    static const int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template <>
struct Fibonacci<1>{
    static const int value = 1;
};

template <>
struct Fibonacci<0>{
    static const int value = 0;
};

int main(){
    std::cout << Fibonacci<5>::value << std::endl;
    return 0;
}