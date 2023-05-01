#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> mylist = { 10, 20, 30, 40, 50 };
    
    forward_list<int>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); ++it) {
        cout << *it << " ";
    }
    
    return 0;
}
