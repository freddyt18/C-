/**
 * Atomic variables in C++ provide a way to perform atomic operations on variables shared between threads, ensuring that each operation is executed as a single, indivisible unit. This eliminates the possibility of data races and ensures thread safety.
 * 
 * In this example, we create an atomic integer variable called sharedValue and initialize it to zero. 
 * 
 * We then define a function called incrementValue that will increment this shared variable by 1,000,000 times. 
 * 
 * We create two threads that will call this function and run concurrently. 
 * 
 * Once the threads have finished running, we print out the final value of sharedValue to confirm that the increments have been applied correctly.
 **/
void NOTE(){};


#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> sharedValue(0);

void incrementValue() {
    for (int i = 0; i < 1000000; i++) {
        sharedValue++;
    }
}

int main() {
    std::thread t1(incrementValue);
    std::thread t2(incrementValue);
    
    t1.join();
    t2.join();
    
    std::cout << "Shared value: " << sharedValue << std::endl;
    
    return 0;
}
