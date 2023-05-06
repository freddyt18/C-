# Constexpr

Constexpr functions are functions that can be evaluated at compile-time, allowing for optimization opportunities and improved performance. Here's an overview of the key concepts related to constexpr functions:

### Syntax
A constexpr function is declared using the `constexpr` keyword before the function name and return type. The function must be defined in a way that allows it to be evaluated at compile-time, meaning that it must only contain expressions that can be evaluated at compile-time, and it must not contain any runtime-only constructs such as loops, `new` and `delete` operators, or function calls that are not themselves constexpr.

```cpp
constexpr int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
```

### Requirements
To be eligible for evaluation at compile-time, a constexpr function must meet the following requirements:
- The function must have a return type that is a literal type (such as int, float, or pointer).
- The function parameters must be literal types.
- The function body must contain only expressions that are evaluatable at compile-time. 

### Advantages
There are several advantages to using constexpr functions:
- Improved performance: Constexpr functions can be evaluated at compile-time, allowing for better performance and optimization opportunities.
- Improved code readability: The use of constexpr functions can make code more readable and expressive, especially when dealing with compile-time computations.
- Increased correctness: Since constexpr functions are evaluated at compile-time, errors can be detected earlier in the development process.
