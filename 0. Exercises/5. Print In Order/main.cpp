#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx_1, mtx_2;
condition_variable cv_1, cv_2;

class Foo {
public:
    Foo() {}

    /**
     * This function prints "first" and sets a flag to indicate that it has finished executing.
     * 
     * @param printFirst printFirst is a function that takes no arguments and returns no value. It is a
     * callback function that is passed as a parameter to the first() function. The purpose of this
     * function is to print the string "first".
     */
    void first(function<void()> printFirst) {
        lock_guard<mutex> lock(mtx_1);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ready_1 = true;
        cv_1.notify_one();
    }

    /**
     * This function prints "second" after the first function has finished and notifies the third
     * function to proceed.
     * 
     * @param printSecond printSecond is a function that takes no arguments and returns nothing (void).
     * It is a callback function that is passed as a parameter to the second() function. When called,
     * it outputs the string "second".
     * 
     * @return Nothing is being returned. This is a void function.
     */
    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx_1);
        cv_1.wait(lock, [this]() {return ready_1;});
        lock_guard<mutex> lock2(mtx_2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ready_2 = true;
        cv_2.notify_one();
    }

    /**
     * The function "third" waits for a signal from another thread and then calls a function to print
     * "third".
     * 
     * @param printThird printThird is a function pointer to a function that takes no arguments and
     * returns nothing. It is a callback function that will be called by the third() function to print
     * the string "third".
     * 
     * @return The lambda function is returning a boolean value, which is indicating whether the
     * condition for waiting on the condition variable `cv_2` has been met or not. The condition is
     * that the `ready_2` flag should be set to true.
     */
    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx_2);
        cv_2.wait(lock, [this]() {return ready_2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    bool ready_1 = false;
    bool ready_2 = false;
};