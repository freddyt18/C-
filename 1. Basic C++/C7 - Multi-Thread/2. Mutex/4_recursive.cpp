/**
 * In this example, we use a recursive mutex to allow a thread to lock the mutex multiple times without causing a deadlock. The printHello() function calls itself recursively, which would normally cause a deadlock if we were using a regular mutex. However, since we're using a recursive mutex, the thread can lock the mutex multiple times without causing a deadlock. 
 **/
void NOTE(){};


#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex mtx; // recursive mutex for shared resource

void printHello(int id, int count) {
    if (count < 3) {
        mtx.lock(); // lock the mutex
        std::cout << "Thread " << id << ": Hello, World!" << std::endl;
        printHello(id, count + 1); // call recursively
        mtx.unlock(); // unlock the mutex
    }
}

int main() {
    std::thread t1(printHello, 1, 0);

    t1.join();

    return 0;
}
