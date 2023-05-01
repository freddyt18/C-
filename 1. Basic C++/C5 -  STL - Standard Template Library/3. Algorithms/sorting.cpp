#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> myvector = { 10, 20, 30, 40, 50 };
    
    // Sort the elements in ascending order
    sort(myvector.begin(), myvector.end());
    
    // Sort the elements in descending order
    sort(myvector.begin(), myvector.end(), greater<int>());
    
    // Find the median element
    auto it = myvector.begin() + myvector.size()/2;
    nth_element(myvector.begin(), it, myvector.end());
    cout << "Median element: " << *it << endl;
    
    return 0;
}
