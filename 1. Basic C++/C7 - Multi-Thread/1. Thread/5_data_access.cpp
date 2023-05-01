/*  
    When multiple threads access the same data, you need to ensure thread safety to 
    avoid data races and undefined behavior. You can use synchronization primitives 
    like mutexes, condition variables, and atomic variables to ensure thread safety. 
    Here's an example using a mutex:

*/

#include <iostream>
#include <thread>
#include <mutex>
#include <string>


// The std::mutex object mtx is used to protect the shared resource, which 
// in this case is the standard output stream.
std::mutex mtx;

void print(const std::string& str) {

    // A std::lock_guard<std::mutex> object is created with mtx as its argument to ensure
    // that the mutex is locked when the print() function is executed. This prevents both
    // threads from accessing the shared resource at the same time, which could lead to 
    // race conditions and undefined behavior.
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << str << std::endl;
}

int main() {

    // the print() function is called by two separate threads t1 and t2.
    std::thread t1(print, "Hello from thread 1!");
    std::thread t2(print, "Hello from thread 2!");

    t1.join();
    t2.join();

    return 0;
}

/*  
    Note that std::lock_guard automatically releases the mutex lock when it goes out of scope, so there's no need to explicitly unlock the mutex in this example.
*/
