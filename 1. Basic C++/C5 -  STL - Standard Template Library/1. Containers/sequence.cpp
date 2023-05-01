#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main() {
    // vector example
    std::vector<int> myVector {1, 2, 3, 4, 5};
    myVector.push_back(6);
    for (auto i : myVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // deque example
    std::deque<int> myDeque {1, 2, 3, 4, 5};
    myDeque.push_back(6);
    myDeque.push_front(0);
    for (auto i : myDeque) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // list example
    std::list<int> myList {1, 2, 3, 4, 5};
    myList.push_back(6);
    myList.push_front(0);
    for (auto i : myList) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
