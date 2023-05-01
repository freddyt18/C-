#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myvector = { 10, 20, 30, 40, 50 };
    
    vector<int>::iterator it;
    for (it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    vector<int>::reverse_iterator rit;
    for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
    
    vector<int>::iterator it2 = myvector.begin();
    cout << "Element at index 2: " << *(it2+2) << endl;
    
    return 0;
}
