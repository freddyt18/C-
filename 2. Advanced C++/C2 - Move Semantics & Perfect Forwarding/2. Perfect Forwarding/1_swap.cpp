#include <iostream>
#include <string>

using namespace std;

void swap(string&& a, string&& b){
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    string temp = move(a);
    a = move(b);
    b = move(temp);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

}

int main(){

    string a = "Hello";
    string b = "World";

    swap(forward<string>(a), forward<string>(b));

    return 0;
}