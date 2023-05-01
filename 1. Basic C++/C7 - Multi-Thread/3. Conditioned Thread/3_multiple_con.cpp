/**
 * In this example, we have two conditions, ready and processed, that the consumer thread needs to wait for before it can proceed. 
 * 
 * The producer thread generates data and sets the ready flag to true, and then signals the condition variable. After some time, the producer thread sets the processed flag to true and signals the condition variable again. 
 * 
 * The consumer thread waits for both conditions to be true before proceeding, using cv.wait() with a lambda function that returns true only when both conditions are true. 
 * 
 * The cv.notify_all() call is used to wake up all waiting threads.
 * 
 */
void NOTE(){};

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
bool processed = false;

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    while(!ready || !processed) {
        cv.wait(lock);
    }
    std::cout << "Consumer: data is ready and processed." << std::endl;
}

void producer() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_all();
    std::cout << "Producer: data is generated." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);
        processed = true;
    }
    cv.notify_all();
    std::cout << "Producer: data is processed." << std::endl;
}

int main() {
    std::thread t1(consumer);
    std::thread t2(producer);
    t1.join();
    t2.join();
    return 0;
}
