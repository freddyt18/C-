#include <iostream>
#include <vector>
#include <string>


using namespace std;


template <typename T>
struct is_vector_tt {

    template <typename U>
    static constexpr bool is_vector(U&& data) { 
        return (std::is_same_v<U, std::vector<int>> || std::is_same_v<U, std::vector<std::string>>);
    }

    static constexpr bool value = is_vector<T>(nullptr);
};


int main(){

    static_assert(is_vector_tt<std::vector<int>>::value, "Not a vector");
    static_assert(is_vector_tt<std::vector<std::string>>::value, "Not a vector");
    static_assert(!is_vector_tt<int>::value, "Not a vector");
    static_assert(!is_vector_tt<double>::value, "Not a vector");


    return 0;
}