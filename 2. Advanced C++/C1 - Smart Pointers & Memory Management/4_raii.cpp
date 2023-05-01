#include <iostream>
#include <memory>

int main() {
    // allocate memory for an integer and wrap it in a unique pointer
    std::unique_ptr<int> ptr(new int(10)); 


    // print the value stored in the integer
    std::cout << *ptr << std::endl; 


    // the memory will be automatically freed when the unique pointer goes out of scope
    return 0;
}


/**
 * RAII stands for Resource Acquisition Is Initialization
 * 
 * In this example, we've used a std::unique_ptr to manage the lifetime of a dynamically allocated integer. 
 * 
 * When the unique pointer goes out of scope, the memory allocated for the integer will be automatically released. 
 * 
 * This eliminates the need to manually call delete on the pointer, which can lead to memory leaks and other issues.
 * 
 * -
 * 
 * RAII can also be used to manage other types of resources, such as files and locks. 
 * 
 * For example, the std::ofstream class in C++ uses RAII to automatically close the file when the object goes out of scope.
 */
void NOTE(){};