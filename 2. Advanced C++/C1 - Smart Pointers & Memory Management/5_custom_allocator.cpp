#include <iostream>
#include <vector>

template<typename T>
class MyAllocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;

    MyAllocator() = default;
    ~MyAllocator() = default;

    template<typename U>
    MyAllocator(const MyAllocator<U>&) {}

    pointer allocate(size_type n) {
        return static_cast<pointer>(::operator new(n * sizeof(T)));
    }

    void deallocate(pointer p, size_type n) {
        ::operator delete(p);
    }
};

int main() {
    std::vector<int, MyAllocator<int>> v{1, 2, 3, 4, 5};
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}


/**
 * In this example, we define a custom allocator MyAllocator that uses operator new and operator delete for memory allocation and deallocation. 
 * 
 * We then use this allocator with a std::vector of ints. 
 * 
 * When constructing the vector, we pass our allocator as the second template argument. 
 * 
 * The vector will then use our allocator for memory management. 
 * 
 * In this case, the vector is constructed with some initial values and is printed to the console. Finally, the program exits.

 */
void NOTE(){};