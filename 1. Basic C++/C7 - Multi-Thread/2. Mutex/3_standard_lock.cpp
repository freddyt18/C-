#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // create a mutex object

void threadFunc(int threadID) {
    std::lock_guard<std::mutex> guard(mtx); // lock the mutex using lock_guard
    std::cout << "Thread " << threadID << " is accessing the shared resource." << std::endl;
    // lock_guard will automatically unlock the mutex when it goes out of scope
}

int main() {
    std::thread t1(threadFunc, 1);
    std::thread t2(threadFunc, 2);

    t1.join();
    t2.join();

    return 0;
}