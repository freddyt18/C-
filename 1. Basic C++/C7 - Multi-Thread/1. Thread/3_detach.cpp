/* 
    You can detach a thread from the calling thread by calling the detach method on the
    thread object. This allows the thread to run independently of the main thread. 
    Here's an example:

*/

#include <iostream>
#include <thread>


void worker() {
    std::cout << "Worker thread started" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Worker thread finished" << std::endl;
}

int main() {

    //the worker function runs in a separate thread and is detached from 
    //the main thread using detach.
    std::thread t(worker);
    t.detach();


    //The main thread continues execution and exits before the worker thread is finished.
    std::cout << "Main thread finished" << std::endl;
    return 0;
}
