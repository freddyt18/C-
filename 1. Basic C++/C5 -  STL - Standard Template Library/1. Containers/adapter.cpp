#include <iostream>
#include <stack>
#include <queue>

int main() {
    // stack example
    std::stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    // queue example
    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    // priority_queue example
    std::priority_queue<int> myPQ;
    myPQ.push(2);
    myPQ.push(1);
    myPQ.push(3);
    while (!myPQ.empty()) {
        std::cout << myPQ.top() << " ";
        myPQ.pop();
    }
    std::cout << std::endl;

    return 0;
}
