/**
 * In this example, we have two threads, a producer and a consumer. 
 * 
 * The producer thread generates data and sets the ready flag to true, then signals the condition variable cv. 
 * 
 * The consumer thread waits for the ready flag to be set to true, and then proceeds to consume the data. 
 * 
 * The cv.wait() call will cause the consumer thread to block until the producer thread signals the condition variable.
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

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    while(!ready) {
        cv.wait(lock);
    }
    std::cout << "Consumer: data is ready." << std::endl;
}

void producer() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
    std::cout << "Producer: data is generated." << std::endl;
}

int main() {
    std::thread t1(consumer);
    std::thread t2(producer);
    t1.join();
    t2.join();
    return 0;
}
