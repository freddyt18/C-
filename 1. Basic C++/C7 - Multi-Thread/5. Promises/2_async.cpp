/**
 * Here's another example that demonstrates the use of std::async, which allows you to execute a function asynchronously and obtain a future object that will hold the result of the function:  
 **/
void NOTE(){};


#include <iostream>
#include <future>
#include <thread>

int calculate()
{
    // This function takes some time to execute
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 42;
}

int main()
{
    std::future<int> future = std::async(std::launch::async, calculate);

    std::cout << "Waiting for result..." << std::endl;

    int result = future.get();

    std::cout << "Result: " << result << std::endl;

    return 0;
}
