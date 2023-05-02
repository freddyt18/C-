# Introduction to Perfect Forwarding

Perfect forwarding is a C++ feature that allows a function to forward its arguments to another function without losing any information or introducing any unnecessary overhead. In other words, perfect forwarding allows a function to pass its arguments along to another function, as if they were passed directly by the caller.

> Before diving into the details of perfect forwarding, it's important to first understand the concept of reference collapsing. When you pass a variable as an argument to a function, you can either pass it by value or by reference. Passing by value creates a copy of the variable, while passing by reference allows the function to access the original variable.

## lvalue References VS rvalue References

There are two types of references in C++: **lvalue references** and **rvalue references**. 

An lvalue reference can only refer to an object that has a name and exists in memory, while an rvalue reference can only refer to a temporary object that does not have a name.

Here's a table summarizing the differences between rvalue references and lvalue references


|     | Lvalue References | Rvalue References |
| --- | ----------------- | ----------------- |
| Syntax | `T&` | `T&&` |
| Can bind to | Lvalues only | Rvalues only |
| Lifetime | Referenced object must exist for the duration of the reference | Referenced object may be temporary |
| Use case | Modify existing objects or pass objects by reference | Move objects or pass objects by value |
| Example | `int x = 5; int& y = x;` | `int&& z = 10;`

Note that while lvalue references can only bind to lvalues, rvalue references can bind to both rvalues and lvalues, as explained previously.

<hr>

## Reference Collapsing

Reference collapsing is the mechanism by which C++ combines lvalue references and rvalue references to create reference types. When an lvalue reference is combined with an rvalue reference, the result is an lvalue reference. When two rvalue references are combined, the result is an rvalue reference.

### Example

```
void foo(int& x) {
    // do something with x
}

void bar(int&& x) {
    // do something with x
}

template <typename T>
void baz(T&& x) {
    foo(std::forward<T>(x));
    bar(std::forward<T>(x));
}
```

In this example, `foo` and `bar` are two functions that take an lvalue reference and an rvalue reference, respectively. The `baz` function is a template function that takes a forwarding reference, which is denoted by `T&&`. A forwarding reference is a special type of reference that can bind to both lvalues and rvalues.

When `baz` is called with an lvalue argument, `T` is deduced to be an lvalue reference. When `baz` is called with an rvalue argument, `T` is deduced to be an rvalue reference.

### The Role of std::forward

> `std::forward` is a utility function that allows you to forward the argument as an lvalue or rvalue reference, depending on the original argument's value category.

Inside the `baz` function, `std::forward<T>(x)` is used to forward the argument to `foo` and `bar`. 

If `x` is an lvalue, `std::forward<T>(x)` returns an lvalue reference. If `x` is an rvalue, `std::forward<T>(x)` returns an rvalue reference. This ensures that the argument is forwarded in the correct value category, preserving its original value category.

<hr>

## Benefits of Perfect Forwarding

Perfect forwarding has several benefits. First, it allows you to write generic functions that can accept any type of argument, whether it's an lvalue or an rvalue. This makes your code more flexible and reusable.

Second, perfect forwarding avoids unnecessary copies and moves, which can improve performance. When you pass an object by value, the object is copied or moved, which can be expensive for large objects or objects that are expensive to copy or move. With perfect forwarding, you can avoid these unnecessary copies and moves by forwarding the object as is, without creating a copy or move.

## Challenges with Perfect Forwarding

However, it's important to note that perfect forwarding can be tricky, especially when dealing with rvalue references and forwarding template arguments. Here are some common pitfalls to watch out for when using perfect forwarding:

<hr>

### Forwarding lvalue References as rvalue References
This is a common mistake and can lead to unexpected behavior. When forwarding an lvalue reference, the template parameter should be declared as a forwarding reference (using the `&&` notation), which will deduce the reference type of the argument and preserve its lvalue or rvalue-ness.

<hr>

### Overloading Function Templates
When overloading function templates, it can be tricky to get the correct overload to be called. This is because the compiler will prefer non-templated functions to function templates, even if the non-templated function is a worse match. 
>One way to solve this problem is to use tag dispatching, where you create a tag class that is used to select the correct overload.

<hr>

### Ambiguous Overload Resolution
If you have multiple overloaded functions that take forwarding references and you call the function with an argument that could match more than one overload, the compiler may not be able to determine which overload to call. In this case, you can use SFINAE (Substitution Failure Is Not An Error) to remove the overload from consideration if it doesn't meet certain criteria.

<hr>

### Forwarding Arrays
When forwarding arrays, you need to be careful to preserve their size information. This can be done using the `std::forward` function, which will cast the array to an rvalue reference and preserve its size information.

<hr>

### Forwarding Member Function Pointers
When forwarding member function pointers, you need to use the `.*` or `->*` operator to invoke the function on the correct object. This can be tricky to get right, especially when dealing with templates.

<hr>

To avoid these pitfalls, it's important to have a good understanding of the rules for template argument deduction and the behavior of rvalue references. It can also be helpful to use type traits and other template metaprogramming techniques to ensure that the correct overloads are selected and that the types are forwarded correctly.

Overall, perfect forwarding is a powerful technique that can greatly improve the efficiency and flexibility of your code. By using perfect forwarding, you can avoid unnecessary copies and move operations, and create more generic and reusable code. However, it does require some care and attention to use correctly, and it's important to understand the nuances of the technique to avoid common pitfalls.

# Proof of Concept

From exercise 5, here's a table that summarizes the results:

<center>

| Element | Value (ns) | R-Value (ns) |
|---------|------------|--------------|
| 500     | 1207       | 824          |
| 1000    | 2439       | 1699         |
| 1500    | 3784       | 2709         |
| 2000    | 5110       | 3704         |
| 2500    | 6448       | 4717         |
| 3000    | 7680       | 5639         |
| 3500    | 9000       | 6577         |
| 4000    | 10359      | 7563         |
| 4500    | 11578      | 8477         |
| 5000    | 12838      | 9434         |
| 5500    | 14115      | 10386        |
| 6000    | 15506      | 11481        |
| 6500    | 16847      | 12383        |
| 7000    | 18109      | 13233        |
| 7500    | 19442      | 14183        |
| 8000    | 20655      | 15033        |
| 8500    | 21955      | 15955        |
| 9000    | 23364      | 16958        |
| 9500    | 24589      | 17868        |

</center>

Note that the values are in nanoseconds (ns). The "Value" column refers to the execution time for the function that uses pass-by-value, while the "R-Value" column refers to the execution time for the function that uses perfect forwarding (i.e., pass-by-rvalue-reference). As we can see, the perfect forwarding function is consistently slower than the pass-by-value function, which contradicts the initial expectation.