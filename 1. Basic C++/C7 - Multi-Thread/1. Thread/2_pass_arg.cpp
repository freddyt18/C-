/* 
    You can pass arguments to a thread function by either using a function object
    or by using a lambda expression. Here's an example using a lambda expression:

*/

#include <iostream>
#include <thread>
#include <string>



void printHello(std::string name) {
    std::cout << "Hello " << name << " from thread " << std::this_thread::get_id() << std::endl;
}


int main() {

    // printHello function takes a string argument and we
    // pass it to the thread function using a lambda expression.
    std::thread t1([]{ printHello("Alice"); });
    std::thread t2([](const std::string& name){ printHello(name); }, "Bob");
    
    
    // The first thread is created without any argument and the second thread is
    // created with a string argument "Bob".
    t1.join();
    t2.join();
    return 0;
}



