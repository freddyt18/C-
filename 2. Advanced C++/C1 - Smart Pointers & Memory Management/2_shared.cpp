#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sharedPtr(new int(42));
    std::cout << "Reference count: " << sharedPtr.use_count() << std::endl;
    {
        std::shared_ptr<int> sharedPtr2 = sharedPtr;
        std::cout << "Reference count: " << sharedPtr.use_count() << std::endl;
    }
    std::cout << "Reference count: " << sharedPtr.use_count() << std::endl;
    return 0;
}
