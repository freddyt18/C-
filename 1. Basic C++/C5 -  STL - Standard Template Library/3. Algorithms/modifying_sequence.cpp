#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    vector<int> myvector = { 10, 20, 30, 40, 50 };

    // Print all elements
    cout << "Original Vector : ";
    for(int x: myvector){
        cout << x << " ";
    };
    cout << endl;
    
    // Multiply all elements by 2
    for_each(myvector.begin(), myvector.end(), [](int &i){ i*=2; });
    
    // Remove all elements divisible by 3
    myvector.erase(remove_if(myvector.begin(), myvector.end(), [](int i){ return i%3==0; }), myvector.end());

    // Print all elements
    cout << "New Vector: ";
    for(int x: myvector){
        cout << x << " ";
    };

    cout << endl;
    
    // Check if all elements are greater than 5
    bool all_greater_than_five 
        = all_of(
                myvector.begin(), 
                myvector.end(), 
                [](int i){ return i>5; }
            );
    cout << "All elements are greater than 5: " << boolalpha << all_greater_than_five << endl;
    
    return 0;
}
