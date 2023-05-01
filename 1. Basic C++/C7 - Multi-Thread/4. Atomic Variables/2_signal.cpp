/**
 * In this example, we create an atomic boolean variable called ready and initialize it to false. 
 * 
 * We define a function called worker that will loop until ready is set to true, at which point it will perform some work. 
 * 
 * In our main function, we create a thread that will call worker and then wait for 500 milliseconds before setting ready to true. 
 * 
 * Once ready is set to true, the thread will exit and the program will terminate.
 */
void NOTE(){};


#include <iostream>
#include <atomic>
#include <thread>

std::atomic<bool> ready(false);

void worker() {
    std::cout << "Worker: waiting for ready signal...\n";
    while (!ready) {
        std::this_thread::yield();
    }
    std::cout << "Worker: received ready signal, performing work...\n";
    // perform work here
}

int main() {
    std::thread t(worker);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Main: sending ready signal...\n";
    ready = true;
    t.join();
    return 0;
}
