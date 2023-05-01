#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> myvector = { 10, 20, 30, 40, 50 };
    
    // Count the number of elements equal to 30
    int count = std::count(myvector.begin(), myvector.end(), 30);
    cout << "Count of 30: " << count << endl;
    
    // Check if all elements are greater than 5
    bool all_greater_than_five 
        = all_of(
                myvector.begin(), 
                myvector.end(), 
                [](int i){ return i>5; }
            );
    cout << "All elements are greater than 5: " << boolalpha << all_greater_than_five << endl;
    
    // Find the first even element
    auto it = find_if(myvector.begin(), myvector.end(), [](int i){ return i%2==0; });
    cout << "First even element: " << *it << endl;
    
    return 0;
}
