#include <iostream>
#include <string>
#include <typeinfo>
#include <string>

class Person {
    //Reflection is not supported in C++ so we have to manually add the members of the class here
    public:
        std::string name;
        int age;
        double height;
};

// Since reflection is not supported in C++, we will be using custom type traits to get the members of the class and print them out to the console

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
auto print_type_info() {
    return TypeInfo<T>::name;
}


template<typename T>
struct printMembers {
    /**
     * The function prints the type information of the "name", "age", and "height" attributes of an
     * object.
     * 
     * @param obj The parameter "obj" is a reference to an object of type T, which is being passed to
     * the function "print". The function is intended to print out information about the object's name,
     * age, and height.
     */
    static void print(const T& obj) {
        // std::cout << "Type name of this object: " << print_type_info<T>() << std::endl;
        
        std::cout << "Name: " << print_type_info<decltype(obj.name)>() << std::endl;
        std::cout << "Age: " << print_type_info<decltype(obj.age)>() << std::endl;
        std::cout << "Height: " << print_type_info<decltype(obj.height)>() << std::endl;


    }
};


int main(){
    Person p;

    printMembers<Person>::print(p);

    return 0;
}