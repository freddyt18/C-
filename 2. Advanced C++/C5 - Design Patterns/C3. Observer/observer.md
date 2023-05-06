# Observer Pattern

The Observer design pattern is a behavioral pattern that defines a one-to-many relationship between objects, so that when one object changes state, all of its dependents are notified and updated automatically.

In the Observer pattern, there are two main types of objects: the `Subject` and the `Observer`. The `Subject` is the object that is being observed, and the `Observer` is the object that is interested in the state of the `Subject`.

Here's an example of how to implement the Observer pattern in C++:

```cpp
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
    void update() override {
        std::cout << "Observer updated" << std::endl;
    }
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
        for (auto observer : observers) {
            observer->update();
        }
    }

private:
    std::vector<Observer*> observers;
};
```

In this example, we define an `Observer` interface that defines the `update` method, which is called when the `Subject` changes state. We also define a `Subject` interface that provides methods for attaching, detaching, and notifying `Observer` objects.

To use the Observer pattern, you would first create an instance of the `Subject` class, and then attach one or more `Observer` objects to it:

```cpp
ConcreteSubject subject;
ConcreteObserver observer1;
ConcreteObserver observer2;

subject.attach(&observer1);
subject.attach(&observer2);
```

Then, when the state of the `Subject` changes, you would call the `notify` method to notify all attached `Observer` objects:

```cpp
subject.notify();
```

This would call the `update` method on both `Observer` objects that were attached to the `Subject`.

The Observer pattern can be useful in situations where you need to decouple the logic for updating a set of dependent objects from the logic for changing the state of the objects. It can also be useful when you need to notify multiple objects when a single object changes state.

Here's an image showing the structure of the Observer pattern:

![Observer Pattern Structure](https://2.bp.blogspot.com/_mAJDMuyu_WI/TN53bNZZiQI/AAAAAAAAC4w/EthB9OCvjWo/s400/ObserverPattern_example.gif)
Retrieved from [source](https://www.bogotobogo.com/DesignPatterns/images/Observer/Observer.gif).