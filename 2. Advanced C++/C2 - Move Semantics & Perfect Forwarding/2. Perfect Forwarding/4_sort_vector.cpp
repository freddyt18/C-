#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
  string name;
  int age;

  bool operator<(const Person& other) const {
    return name < other.name;
  }
};


// Using Lvalue reference to accept lvalue objects
template <typename T>
void sort_vector(vector<T>& v) {
    sort(
        forward<vector<T>>(v).begin(), 
        forward<vector<T>>(v).end()
    );
}

// Using Rvalue reference to accept rvalue objects
template <typename T>
void sort_vector(vector<T>&& v) {
    sort(v.begin(), v.end());
}



int main() {
    vector<int> v1{5, 2, 8, 1, 9};
    vector<string> v2{"apple", "zebra", "banana", "cherry"};
    vector<Person> v3{{"Alice", 25}, {"Charlie", 20}, {"Bob", 30}, {"Diana", 20}, {"Eve", 25}};

    sort_vector(v1);
    sort_vector(v2);
    sort_vector(move(v3));

    for (const auto& x : v1) {
        cout << x << " ";
    }
    cout << endl;

    for (const auto& x : v2) {
        cout << x << " ";
    }
    cout << endl;

    for (const auto& x : v3) {
        cout << x.name << " (" << x.age << ")" << " ";
    }
    cout << endl;

    return 0;
}
