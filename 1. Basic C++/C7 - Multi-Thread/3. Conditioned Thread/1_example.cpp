/**
 * Condition variables are used to synchronize the execution of threads. They allow one or more threads to wait until a particular condition is met, and then continue execution. In C++, condition variables are implemented using the std::condition_variable class.
 * 
 * In this example, we have two threads: thread1 and thread2. thread1 sets a flag after simulating some work, and then notifies the waiting thread using the cv.notify_one() function. thread2 waits for the condition to be met using the cv.wait(lock) function. The lock argument is an instance of std::unique_lock<std::mutex>, which is used to lock the mutex before waiting. Once the condition is met, thread2 continues execution and does some work.
 * 
 * Note that condition variables should always be used in conjunction with a mutex to avoid race conditions. Also, the while loop in thread2 is necessary to handle spurious wakeups, which can occur when a thread is woken up for reasons other than the condition variable being notified.
 * 
 **/
void NOTE(){};

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void thread1()
{
    // simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    // lock the mutex and set the flag
    std::unique_lock<std::mutex> lock(mtx);
    ready = true;
    
    // notify the waiting thread
    cv.notify_one();
}

void thread2()
{
    // wait for the condition to be met
    std::unique_lock<std::mutex> lock(mtx);
    while (!ready) {
        std::cout << "Waiting for condition..." << std::endl;
        cv.wait(lock);
    }
    
    // do some work after the condition is met
    std::cout << "Condition met!" << std::endl;
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}
