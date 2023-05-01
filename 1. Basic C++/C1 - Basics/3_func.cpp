#include <iostream>
using namespace std;

// Pre-declaring the function
int add(int x, int y);
int increase_by_val(int x);
int increase_by_ref(int &x);

int main() {

    int num1 = 1;
    int num2 = 2;

    cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;

    cout << "Passing num1 to a function that copies only the value - " << increase_by_val(num1) << endl;
    
    cout << "Passing num1 to a function that manipulates its address - " << increase_by_ref(num1);

    return 0;
}

// Modify the function
int add(int x, int y) {
    return x + y;
}

// Passing the argument by Value
int increase_by_val(int x){
    x++;
}

// Passing the argument by Reference
int increase_by_ref(int &x){
    x++;
}