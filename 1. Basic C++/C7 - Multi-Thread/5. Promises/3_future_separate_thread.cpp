/**
 * In this example, we define a function square that takes an integer argument and returns its square. 
 * 
 * We then create a std::future<int> object fut by calling std::async with the std::launch::async policy and passing in the square function and its argument. 
 * 
 * This launches the square function in a separate thread and returns a future object that will eventually hold the result of the function.
 * 
 * -
 * 
 * We then call the get method of the fut object to retrieve the result of the function. 
 * 
 * This call will block until the result is available, at which point it will return the result and store it in the result variable.
 **/
void NOTE(){};


#include <iostream>
#include <future>

int square(int x) {
    return x * x;
}

/**
 * The function uses std::async to asynchronously call the square function with an argument of 5, and
 * then retrieves and prints the result.
 */
int main() {
    std::future<int> fut = std::async(std::launch::async, square, 5);
    int result = fut.get();
    std::cout << "Result: " << result << std::endl;
    return 0;
}
