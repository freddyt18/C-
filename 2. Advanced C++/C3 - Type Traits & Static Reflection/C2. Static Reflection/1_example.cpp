#include <iostream>
#include <string_view>

template<typename T>
struct TypeInfo {
    static constexpr std::string_view name{ "unknown type" };
};

template<>
struct TypeInfo<int> {
    static constexpr std::string_view name{ "int" };
};

template<>
struct TypeInfo<double> {
    static constexpr std::string_view name{ "double" };
};

template<>
struct TypeInfo<std::string> {
    static constexpr std::string_view name{ "std::string" };
};

template<typename T>
void print_type_info() {
    std::cout << "Type name: " << TypeInfo<T>::name << std::endl;
}

int main() {
    print_type_info<int>();
    print_type_info<double>();
    print_type_info<std::string>();
    print_type_info<float>(); // will print "unknown type"
    return 0;
}
