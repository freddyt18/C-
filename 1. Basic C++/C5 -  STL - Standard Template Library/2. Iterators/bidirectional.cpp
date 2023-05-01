#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> mylist = { 10, 20, 30, 40, 50 };
    
    list<int>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    list<int>::reverse_iterator rit;
    for (rit = mylist.rbegin(); rit != mylist.rend(); ++rit) {
        cout << *rit << " ";
    }
    
    return 0;
}
