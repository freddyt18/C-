#include <iostream>
#include <vector>
#include <string>


using namespace std;

// This function is used to check if the type is a vector or not but it is limited to only int and string
template<typename T>
struct is_vector_tt {
    static constexpr bool is_vector(T&& data) {
        return (std::is_same_v<T, std::vector<int>> || std::is_same_v<T, std::vector<std::string>>);
    }

};



int main(){

    cout << "v1 is vector - " << boolalpha << is_vector_tt<vector<int>>::is_vector(move(vector<int>{})) << endl;
    cout << "v2 is vector - " << boolalpha << is_vector_tt<vector<string>>::is_vector(move(vector<string>{})) << endl;

    // The result should be true but due to the limitation of the function, they will return false
    cout << "v3 is vector - " << boolalpha << is_vector_tt<vector<double>>::is_vector(move(vector<double>{})) << endl;
    cout << "v4 is vector - " << boolalpha << is_vector_tt<vector<bool>>::is_vector(move(vector<bool>{})) << endl;
    cout << "v5 is vector - " << boolalpha << is_vector_tt<vector<vector<int>>>::is_vector(move(vector<vector<int>>{})) << endl;


    return 0;
}