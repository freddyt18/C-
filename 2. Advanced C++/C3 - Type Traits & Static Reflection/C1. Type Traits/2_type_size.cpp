#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


template <typename T>
struct type_size{
    public: static constexpr size_t value = sizeof(T);
};


int main(){

    cout << "int: " << type_size<int>::value << " bytes" << endl;
    cout << "double: " << type_size<double>::value << " bytes" << endl;
    cout << "string: " << type_size<string>::value << " bytes" << endl;
    cout << "vector<int>: " << type_size<vector<int>>::value << " bytes" << endl;
    cout << "map<int, string>: " << type_size<map<int, string>>::value << " bytes" << endl;


    return 0;
}