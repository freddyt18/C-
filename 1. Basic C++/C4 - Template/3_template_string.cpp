#include <iostream>
#include <string>


template <typename T>
void print(T value) {
    std::cout << value << std::endl;
}

template <>
void print<char>(char value) {
    std::cout << "Character: " << value << std::endl;
}

// Template specialization for a specific data type (e.g., char)

int main() {
    int a = 5;
    print(a);
    
    float b = 2.5;
    print(b);
    
    char c = 'A';
    print(c);

    std::string d = "Dog";
    print(d);
    
    return 0;
}
