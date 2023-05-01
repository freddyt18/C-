#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sharedPtr(new int(42));
    std::weak_ptr<int> weakPtr(sharedPtr);
    std::cout << "Reference count: " << sharedPtr.use_count() << std::endl;
    if (auto sharedPtr2 = weakPtr.lock()) {
        std::cout << "Weak pointer is pointing to: " << *sharedPtr2 << std::endl;
        std::cout << "Reference count: " << sharedPtr.use_count() << std::endl;
    } else {
        std::cout << "Weak pointer is no longer pointing to an object." << std::endl;
    }
    return 0;
}
