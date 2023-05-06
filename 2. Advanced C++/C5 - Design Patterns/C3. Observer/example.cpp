#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Observer {
public:
    virtual ~Observer() {}
    virtual void update() = 0;
};

class Subject {
public:
    virtual ~Subject() {}
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update() override {
        std::cout << name << " received an update from the subject" << std::endl;
    }

private:
    std::string name;
};

class ConcreteSubject : public Subject {
public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        std::cout << "Subject is notifying observers..." << std::endl;

        for (auto observer : observers) {
            observer->update();
        }
    }

    void setState(const std::string& newState) {
        state = newState;
        notify();
    }

private:
    std::vector<Observer*> observers;
    std::string state;
};

int main() {
    ConcreteSubject subject;
    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setState("New State");

    subject.detach(&observer1);

    subject.setState("Another New State");

    return 0;
}
