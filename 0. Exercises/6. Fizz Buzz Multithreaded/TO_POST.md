# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The code uses a mutex and condition variable to synchronize the output of the different methods (fizz, buzz, fizzbuzz, and number) and ensure that they are executed in the correct order. 

The wait conditions for each method are defined using lambda functions. 

The private member variable "i" keeps track of the current number being printed and is incremented in each method after the corresponding output has been printed. 


# Approach
<!-- Describe your approach to solving the problem. -->
The approach used in this code is known as multi-threaded programming, which involves creating multiple threads of execution that can run concurrently to perform different tasks or parts of a task. 

The use of a mutex and condition variable is a common technique for synchronizing the access to shared resources or coordinating the execution of different threads. This approach is widely used in systems programming, parallel computing, and distributed computing, among other areas.
> This approach simplifies the logic of the wait conditions and avoids duplicating code in each method, resulting in a concise and efficient implementation of the FizzBuzz problem.


# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
The time complexity of this code is O(n), where n is the maximum number to be printed. This is because each number from 1 to n is printed exactly once. 

The time complexity of each of the four methods (fizz, buzz, fizzbuzz, and number) is also O(n), as each method is called exactly n/3, n/5, n/15, and (n - n/3 - n/5 + n/15) times respectively, which simplifies to O(n) for each method. The use of multi-threading does not affect the time complexity of the code, as each thread executes the same amount of work and the threads are synchronized to ensure that the output is printed in the correct order.

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
The space complexity of this code is O(1), which is constant space complexity. 

This is because the code does not use any data structures that grow in size with the input size n. 

The only memory usage is for the private member variables "n" and "i", which are integers and therefore have a constant size, as well as the mutex and condition variable, which are also constant in size. The code does not allocate any dynamic memory or use any other data structures that grow with n. Therefore, the space complexity of the code is constant and does not depend on the input size.

# Code
```

class FizzBuzz {
private:
    int n;
    int i;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{return (i % 3 == 0 && i % 5 != 0) || i > n;});
            if (i > n) return;
            printFizz();
            ++i;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{return (i % 5 == 0 && i % 3 != 0) || i > n;});
            if (i > n) return;
            printBuzz();
            ++i;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{return i % 15 == 0 || i > n;});
            if (i > n) return;
            printFizzBuzz();
            ++i;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{return (i % 3 != 0 && i % 5 != 0) || i > n;});
            if (i > n) return;
            printNumber(i);
            ++i;
            cv.notify_all();
        }
    }

private:
    mutex m;
    condition_variable cv;
};

```