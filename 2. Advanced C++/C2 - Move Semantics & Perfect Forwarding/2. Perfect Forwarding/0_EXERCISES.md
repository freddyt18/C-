# Exercises

1. "Swap with Perfect Forwarding"

    Write a `swap` function that uses perfect forwarding to swap the values of two objects. 
    
    The function should take two forwarding references as arguments and should swap the values of the objects that they refer to.

2. "Generic Printing Function"

    Write a generic function that prints the value of any object passed to it. The function should use perfect forwarding to accept any type of argument, and should print the value of the argument to the console.

3. "Calculate Sum of Elements"

    Write a function that calculates the sum of all elements in a container. The function should use perfect forwarding to accept any container type and should return the sum of all the elements in the container.

4. "Sort Vector of Any Type with Perfect Forwarding"

    Write a function sort_vector that can sort a vector of any type using perfect forwarding. The function should take a vector by rvalue reference, sort it in place using the std::sort algorithm, and return the sorted vector. The function should be able to handle vectors of any type that can be sorted using std::sort, including custom types that have an overloaded < operator.

5. "Perfect Forwarding Performance"

    1. Generate a large vector of objects (e.g., a vector of 1000000 integers, or a vector of 1000000 custom objects).
    2. Implement a function that takes the vector by value and sorts it using the standard std::sort algorithm.
    3. Implement another function that takes the vector by rvalue reference and sorts it using std::sort and perfect forwarding.
    4. Measure the time it takes to sort the vector using both functions and compare the execution times. 
    5. Make sure to run each function multiple times and average the execution times to get accurate measurements. You can use the <chrono> library to measure the execution times.