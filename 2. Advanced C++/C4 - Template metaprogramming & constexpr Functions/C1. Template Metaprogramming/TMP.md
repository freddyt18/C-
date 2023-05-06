# Template metaprogramming (TMP)

Template metaprogramming (TMP) is a technique in C++ that allows programmers to perform computations at compile-time using templates. In other words, you can use templates to generate code that is evaluated by the compiler at compile-time instead of run-time.

The basic idea behind TMP is to use the power of the C++ type system to perform computations. Templates are used to create type-level values that can be manipulated using template metaprogramming techniques such as recursion, conditional compilation, and template specialization.

Here's an example of a simple TMP function that calculates the factorial of a number:

```cpp
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr int value = 1;
};
```

In this example, we define a template class `Factorial` that takes an integer value as a template parameter. The class contains a static member variable called `value` that stores the factorial of the template parameter.

The `Factorial` class is defined using template specialization to handle the base case (when the template parameter is 0) and recursion to handle the general case (when the template parameter is greater than 0).

We can use this template class to calculate the factorial of a number at compile-time, like this:

```cpp
constexpr int fact = Factorial<5>::value; // fact = 120
```

In this case, the value of `fact` is calculated by the compiler at compile-time, using the template class `Factorial`.

This is just a simple example, but template metaprogramming can be used to perform much more complex computations at compile-time, such as generating code, performing type calculations, and optimizing code.
