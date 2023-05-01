/**
 * Futures and promises are used for asynchronous programming in C++. 
 * 
 * They allow you to write code that can execute concurrently and can communicate with each other through shared data structures.
 * 
 * A future represents a value that is not yet available but will be available at some point in the future. 
 * A promise is a way to provide a value to a future.
 * 
 * -
 * 
 * In this example, we create a promise object that will eventually provide an integer value to a future object. 
 * 
 * We then create a thread that sets the value of the promise object to 42. 
 * 
 * Meanwhile, in the main thread, we wait for the future object to become available by calling its get method. 
 * 
 * Once the future object has a value, we print it out.
 */
void NOTE(){};

#include <iostream>
#include <future>

int main()
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread t([&promise]{
        promise.set_value(42);
    });

    std::cout << "Waiting for value..." << std::endl;

    int value = future.get();

    std::cout << "Got value: " << value << std::endl;

    t.join();

    return 0;
}
