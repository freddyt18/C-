#include <iostream>

using namespace std;

class Base {
public:
    virtual void foo() {}
};

class Derived : public Base {
public:
    void bar() {}
};

int main() {
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b);
    if (d != nullptr) {
        d->bar();
    } else {
        cout << "dynamic_cast failed" << endl;
    }
    delete b;
    return 0;
}

/**
 * In this example, we have a class hierarchy with a base class Base and a derived class Derived. 
 * 
 * We create a pointer to a Base object, but we know that it actually points to a Derived object. 
 * 
 * We then use dynamic_cast to convert the Base pointer to a Derived pointer so that we can call Derived member functions. 
 * 
 * If the conversion fails (e.g., if the Base pointer did not actually point to a Derived object), dynamic_cast returns a null pointer.
 */
void NOTE(){};