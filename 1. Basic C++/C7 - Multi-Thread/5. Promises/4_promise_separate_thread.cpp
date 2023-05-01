/**
 * In this example, we define a function square that takes an integer argument and a reference to a std::promise<int> object. 
 * 
 * The function simply calculates the square of the argument and sets the value of the promise to the result.
 * 
 * In the main function, we create a std::promise<int> object prom and a std::future<int> object fut by calling the get_future method of the prom object. 
 * We then launch a separate thread by calling std::thread with the square function, its argument, and a reference to the prom object.
 * 
 * -
 * 
 * Once the thread has completed its work, we retrieve the result by calling the get method of the fut object. 
 * 
 * This call will block until the result is available, at which point it will return the result and store it in the result variable.
 **/
void NOTE(){};


#include <iostream>
#include <future>

void square(int x, std::promise<int>& prom) {
    prom.set_value(x * x);
}

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    std::thread t(square, 5, std::ref(prom));
    t.join();
    int result = fut.get();
    std::cout << "Result: " << result << std::endl;
    return 0;
}
