/**
 * Lock classes in C++ provide a more convenient and safer way to lock and unlock a mutex
 * They ensure that the mutex is always unlocked, even in the case of an exception being
 * thrown. There are two main lock classes in C++: std::unique_lock and std::lock_guard.
 * 
 **/
void NOTE(){};

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // create a mutex object

/*  
    In this example, we use std::unique_lock to lock the mutex in the thread function. We create a std::unique_lock object named lock, passing in the mutex object mtx as an argument. This locks the mutex when the std::unique_lock object is created, and automatically unlocks it when the std::unique_lock object goes out of scope (i.e. when the function returns).
*/

void threadFunc(int threadID) {
    std::unique_lock<std::mutex> lock(mtx); // lock the mutex using unique_lock
    std::cout << "Thread " << threadID << " is accessing the shared resource." << std::endl;
    // unique_lock will automatically unlock the mutex when it goes out of scope
}

int main() {
    std::thread t1(threadFunc, 1);
    std::thread t2(threadFunc, 2);

    t1.join();
    t2.join();

    return 0;
}
