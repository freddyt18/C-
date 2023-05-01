#include <iostream>
#include <set>
#include <map>

int main() {
    // set example
    std::set<int> mySet {5, 3, 1, 4, 2};
    mySet.insert(6);
    for (auto i : mySet) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // map example
    std::map<std::string, int> myMap {{"apple", 5}, {"banana", 3}, {"cherry", 1}};
    myMap.insert({"date", 4});
    for (auto i : myMap) {
        std::cout << i.first << ": " << i.second << std::endl;
    }

    return 0;
}
