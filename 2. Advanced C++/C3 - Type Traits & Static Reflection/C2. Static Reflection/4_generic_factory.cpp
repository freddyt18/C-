#include <iostream>
#include <string>
#include <typeinfo>
#include <string>

class Person
{
public:
    std::string name;
    int age;
    double height;

    Person(const std::string &name, int age, double height) : name(name), age(age), height(height) {}
};

template <typename T>
struct TypeInfo
{
    static constexpr std::string_view name{"unknown type"};
};

template <>
struct TypeInfo<int>
{
    static constexpr std::string_view name{"int"};
};

template <>
struct TypeInfo<double>
{
    static constexpr std::string_view name{"double"};
};

template <>
struct TypeInfo<std::string>
{
    static constexpr std::string_view name{"std::string"};
};

template <>
struct TypeInfo<Person>
{
    static constexpr std::string_view name{"Person"};
};

template <typename T>
auto print_type_info()
{
    return TypeInfo<T>::name;
}

template <typename T>
struct printMembers
{
    static void print(T *&&obj)
    {
        std::cout << "Name: " << print_type_info<decltype(obj->name)>() << std::endl;
        std::cout << "Age: " << print_type_info<decltype(obj->age)>() << std::endl;
        std::cout << "Height: " << print_type_info<decltype(obj->height)>() << std::endl;
    }
};

template <typename T, typename... Args>
T *factory(const std::string &name, Args &&...args)
{
    if (name == print_type_info<T>())
    {
        return new T(std::forward<Args>(args)...);
    }
    return nullptr;
}

int main()
{
    auto person_ptr = factory<Person>("Person", "John Smith", 25, 1.8);
    auto person1_ptr = factory<Person>("Person", "Dave Feloni", 35, 2.3);
    auto person2_ptr = factory<Person>("Person", "Jessica Johannson", 25, 2.1);
    
    if (person_ptr)
    {

        std::cout << "Name: " << person_ptr->name << std::endl;
        printMembers<Person>::print(std::move(person_ptr));

        std::cout << "\nName: " << person1_ptr->name << std::endl;
        printMembers<Person>::print(std::move(person1_ptr));

        std::cout << "\nName: " << person2_ptr->name << std::endl;
        printMembers<Person>::print(std::move(person2_ptr));

        delete person_ptr;
        delete person1_ptr;
        delete person2_ptr;
    }
    else
    {
        std::cout << "Unknown type name: Person" << std::endl;
    }
    

    return 0;
}
