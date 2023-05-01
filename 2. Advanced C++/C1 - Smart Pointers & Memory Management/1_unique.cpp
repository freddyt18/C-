#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> myPtr(new int(42));
    std::cout << "My pointer value: " << *myPtr << std::endl;
    // Use of release
    int* rawPtr = myPtr.release();
    // Now the unique pointer no longer owns the object
    std::cout << "Raw pointer value: " << *rawPtr << std::endl;
    delete rawPtr;
    return 0;
}
