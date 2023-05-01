#include <iostream>
#include <thread>

// This function will be run in a separate thread
void thread_function() {
    std::cout << "Hello from thread!\n";
}

int main() {
    // Create a new thread and run the thread_function in it
    std::thread my_thread(thread_function);

    std::cout << "Hello from main!\n";

    // Wait for the thread to finish
    my_thread.join();

    return 0;
}
