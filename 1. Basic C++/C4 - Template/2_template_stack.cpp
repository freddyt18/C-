#include <iostream>

// Class template for a generic stack

template <typename T>
class Stack {
    private:
        T* data;
        int top;
        int size;

    public:
        Stack(int n) {
            size = n;
            top = -1;
            data = new T[n];
        }
        ~Stack() {
            delete[] data;
        }
        void push(T element) {
            if (top == size-1) {
                std::cout << "Stack Overflow" << std::endl;
                return;
            }
            top++;
            data[top] = element;
        }
        T pop() {
            if (top == -1) {
                std::cout << "Stack Underflow" << std::endl;
                return T();
            }
            T temp = data[top];
            top--;
            return temp;
        }
};

int main() {

    Stack<int> intStack(5);
    intStack.push(10); intStack.push(20); intStack.push(30);

    std::cout << intStack.pop() << std::endl;
    std::cout << intStack.pop() << std::endl;
    std::cout << intStack.pop() << std::endl;

    
    Stack<float> floatStack(3);
    floatStack.push(2.5); floatStack.push(3.7);
    
    std::cout << floatStack.pop() << std::endl;
    std::cout << floatStack.pop() << std::endl;
    return 0;
}
