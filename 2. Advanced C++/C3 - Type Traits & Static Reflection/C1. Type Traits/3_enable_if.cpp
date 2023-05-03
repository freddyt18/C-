#include <iostream>
#include <type_traits>


using namespace std;


template <typename T>
typename enable_if<is_integral<T>::value, T>::type
increment(T value) {
    return value + 1;
}

template <typename T>
typename enable_if<!is_integral<T>::value, T>::type
increment(T value) {
    static_assert(is_integral<T>::value, "Type must be integral");
}

int main() {
    cout << increment(10) << endl; // should output 11
    // uncomment line below to see the static_assertion failure
    // cout << increment("hello") << endl; 
    return 0;
}
