# Exercises 

## Exercise 1: Easy - "Factorial"

### Requirements
Write a template metaprogram that calculates the factorial of a given number using recursion.

### Expected Output
```cpp
static_assert(Factorial<5>::value == 120, "Factorial of 5 should be 120");
```

## Exercise 2: Moderate - "Fibonacci"

### Requirements
Write a template metaprogram that calculates the nth number in the Fibonacci sequence using recursion.

### Expected Output
```cpp
static_assert(Fibonacci<5>::value == 5, "Fibonacci of 5 should be 5");
```

## Exercise 3: Hard - "Type List"

### Requirements
Write a template metaprogram that implements a type list, which is a compile-time list of types. The type list should be able to perform the following operations: 

- `PushFront`: Add a new type to the front of the list.
- `PopFront`: Remove the first type in the list.
- `Back`: Get the last type in the list.

### Expected Output
```cpp
using list = TypeList<int, double, char>;
static_assert(std::is_same_v<PushFront_t<list, bool>, TypeList<bool, int, double, char>>, "PushFront operation failed");
static_assert(std::is_same_v<PopFront_t<list>, TypeList<double, char>>, "PopFront operation failed");
static_assert(std::is_same_v<Back_t<list>, char>, "Back operation failed");
```

I hope these exercises are helpful for practicing template metaprogramming! Let me know if you have any questions.