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

// Since reflection is not supported in C++, we will be using custom type traits to get the members of the class and serialize them into a string

template<typename T>
struct serialize {
    static std::string to_string(const T& obj) {
        std::string result = "{ ";
        result += "Name: " + serialize<decltype(obj.name)>::to_string(obj.name) + ", ";
        result += "Age: " + serialize<decltype(obj.age)>::to_string(obj.age) + ", ";
        result += "Height: " + serialize<decltype(obj.height)>::to_string(obj.height) + " }";
        return result;
    }
};

template<>
struct serialize<int> {
    static std::string to_string(const int& obj) {
        return std::to_string(obj);
    }
};

template<>
struct serialize<double> {
    static std::string to_string(const double& obj) {
        return std::to_string(obj);
    }
};

template<>
struct serialize<std::string> {
    static std::string to_string(const std::string& obj) {
        return "\"" + obj + "\"";
    }
};

int main(){
    Person p{"Alice", 25, 1.75};
    std::string serialized = serialize<Person>::to_string(p);
    std::cout << serialized << std::endl;
    return 0;
}
