#include <iostream>
#include <new> // required for placement new

class MyClass {
public:
  MyClass() {
    std::cout << "Constructor called." << std::endl;
  }
  ~MyClass() {
    std::cout << "Destructor called." << std::endl;
  }
};

int main() {
  char* buffer = new char[sizeof(MyClass)]; // allocate memory for MyClass
  MyClass* obj = new (buffer) MyClass; // construct MyClass at buffer
  obj->~MyClass(); // explicitly call the destructor
  delete[] buffer; // deallocate memory
  return 0;
}

/**
 * In this example, we allocate memory for MyClass using the regular new operator. 
 * 
 * Then we create an object of MyClass at the memory location provided by buffer using placement new. 
 * 
 * We then call the destructor of MyClass explicitly using the ~MyClass() syntax since we used placement new to create the object. 
 * 
 * Finally, we deallocate the memory for buffer.
 */
void NOTE(){};