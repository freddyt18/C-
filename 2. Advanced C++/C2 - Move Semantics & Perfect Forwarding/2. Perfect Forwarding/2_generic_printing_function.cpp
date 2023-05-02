#include <iostream>
#include <string>

using namespace std;

template <typename T, typename T1, typename T2>
void print_perfect_forward(T&& t, T1&& t2, T2&& t3){
    cout << forward<T>(t) << endl;
    cout << forward<T1>(t2) << endl;
    cout << forward<T2>(t3) << endl;
};

int main(){
    print_perfect_forward(1, string("b"), 3.14);
    return 0;
}