#include <iostream>
#include <vector>
#include <string>

using namespace std;


/* 
    • This is a variadic template function that takes any number of arguments of any type and returns their sum. 
    
    • The `typename... T` is a parameter pack that allows the function to accept any number of arguments of any type. 
    
    • The `auto` return type deduction is used to deduce the return type based on the type of the arguments passed to the function. 
    
    • The `forward<T>(t)` is used to forward the arguments to the sum function, preserving their value category (lvalue or rvalue). 
    
    • The `+ ...` is a fold expression that expands the parameter pack and sums all the elements. 
*/
template <typename... T>
auto sum_elements(T&&... t){
    return (forward<T>(t) + ...); 
};

int main(){

    cout << sum_elements(1, 2, 3, 4, 5) << endl;
    cout << sum_elements(1.1, 2.2, 3.3, 4.4, 5.5) << endl;
    cout << sum_elements(string("Hello"), string(" "), string("World")) << endl;
    
    return 0;
}