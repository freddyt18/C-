#include <iostream>


// TypeList is a list of types.
template <typename... Ts>
struct TypeList{};

// PushFront: Add a new type to the front of the list.
template <typename T, typename... Ts>
struct PushFront;

template <typename T, typename... Ts>
struct PushFront<T, TypeList<Ts...>>{
    using type = TypeList<T, Ts...>;
};

// PopFront: Remove the first type of the list.
template <typename... Ts>
struct PopFront;

template <typename T, typename... Ts>
struct PopFront<TypeList<T, Ts...>>{
    using type = TypeList<Ts...>;
};

template <>
struct PopFront<TypeList<>>{
    using type = TypeList<>;
};

// Back: Get the last type of the list.
template <typename... Ts>
struct Back;

template <typename T>
struct Back<TypeList<T>>{
    using type = T;
};

template <typename T, typename... Ts>
struct Back<TypeList<T, Ts...>>{
    using type = typename Back<TypeList<Ts...>>::type;
};

int main(){

    using list = TypeList<int, double, char>;
    using list2 = PushFront<float, list>::type;
    using list3 = PopFront<list2>::type;

    // The result is false becuase Back<list3>::type is char and not double.
    std::cout << 
        std::boolalpha << 
        std::is_same<
            Back<list3>::type, 
            double
        >::value 
    << std::endl;

    
    using list4 = TypeList<int, double, char>;
    using list5 = PushFront<float, list4>::type;
    using list6 = PopFront<list5>::type;

    // The result is true becuase Back<list6>::type is char.
    std::cout << 
        std::boolalpha << 
        std::is_same<
            Back<list6>::type, 
            char
        >::value 
    << std::endl;

    return 0;
}