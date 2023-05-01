#include <iostream>
#include <exception>

class MyException : public std::exception
{
    public:
        MyException(const char* msg) : m_msg(msg) {}
        const char* what() const noexcept override { return m_msg; }
    
    private:
        const char* m_msg;
};

int main()
{
    try {
        int num = 10;
        if (num > 5) {
            throw MyException("Number is greater than 5");
        }
    }
    catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
