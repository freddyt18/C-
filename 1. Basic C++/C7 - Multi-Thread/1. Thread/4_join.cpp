/*  
    You can wait for a thread to finish its execution by calling the join method on 
    the thread object. Here's an example:
*/

#include <iostream>
#include <thread>


void worker() {
    std::cout << "Worker thread started" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Worker thread finished" << std::endl;
}

int main() {
    
    // the worker function runs in a separate thread and the main thread waits for the worker thread to finish using join.
    std::thread t(worker);
    std::cout << "Main thread waiting for worker thread to finish..." << std::endl;

    t.join();
    
    std::cout << "Worker thread finished, main thread exiting" << std::endl;
    return 0;
}