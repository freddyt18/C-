Sure! Here are three exercises for practicing with constexpr functions:

### Easy: Compute Fibonacci number at compile-time
Write a `constexpr` function that computes the nth Fibonacci number at compile-time.

**Requirements**
- The function should take a single integer argument `n`.
- The function should return the nth Fibonacci number.
- The function should be evaluated at compile-time.

**Expected Output**
```cpp
static_assert(fib(0) == 0);
static_assert(fib(1) == 1);
static_assert(fib(2) == 1);
static_assert(fib(5) == 5);
static_assert(fib(10) == 55);
```

### Moderate: Compute Factorial of N at Compile-Time
Write a `constexpr` function that computes the factorial of a given number at compile-time.

**Requirements**
- The function should take a single integer argument `n`.
- The function should return the factorial of `n`.
- The function should be evaluated at compile-time.

**Expected Output**
```cpp
static_assert(factorial(0) == 1);
static_assert(factorial(1) == 1);
static_assert(factorial(5) == 120);
static_assert(factorial(10) == 3628800);
```

### Hard: Generate N-Dimensional Array at Compile-Time
Write a `constexpr` function that generates an N-dimensional array at compile-time.

**Requirements**
- The function should take two template arguments `N` and `T`, where `N` is the number of dimensions and `T` is the type of the array elements.
- The function should take a variable number of integer arguments, representing the size of each dimension.
- The function should return a `std::array` object representing the N-dimensional array.
- The function should be evaluated at compile-time.

**Expected Output**
```cpp
constexpr auto arr = makeNDArray<int, 3>({{1, 2}, {3, 4}, {5, 6}});
static_assert(arr[1][0][1] == 4);
```

I hope you find these exercises helpful! Let me know if you have any questions or if you'd like to dive deeper into any specific aspect of constexpr functions.