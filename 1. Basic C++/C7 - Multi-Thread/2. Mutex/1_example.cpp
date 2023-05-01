/**
 * Mutex stands for "Mutual Exclusion", which is a technique used to synchronize access to shared resources or data structures in a multi-threaded environment. Mutex provides a way to ensure that only one thread is allowed to access a shared resource at a time, preventing race conditions and other synchronization problems.
 * 
 * In this example, we create a std::mutex object named mtx. Inside the thread function, we
 * lock the mutex before accessing the shared resource using mtx.lock(). Once the thread is
 * done accessing the shared resource, we unlock the mutex using mtx.unlock().
 * 
 * When a thread calls mtx.lock(), it will block until the mutex is available, which means it
 * has been unlocked by any other thread that has previously locked it. This ensures that only
 * one thread can access the shared resource at a time.
**/
void NOTE(){};


#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // create a mutex object


void threadFunc(int threadID) {
    mtx.lock(); // lock the mutex
    std::cout << "Thread " << threadID << " is accessing the shared resource." << std::endl;
    mtx.unlock(); // unlock the mutex
}

int main() {
    std::thread t1(threadFunc, 1);
    std::thread t2(threadFunc, 2);

    t1.join();
    t2.join();

    return 0;
}


