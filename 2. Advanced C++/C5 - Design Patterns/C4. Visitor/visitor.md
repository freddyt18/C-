# Visitor Pattern

The Visitor pattern is a behavioral pattern that allows you to define a new operation on a group of objects without changing the classes of the objects themselves. It separates the algorithm from the object structure, which makes it easier to add new operations without modifying the existing classes.

In the Visitor pattern, there are two main types of objects: the `Visitor` and the `Element`. The `Visitor` defines the new operation, and the `Element` is the object on which the operation is performed.

Here's an example of how to implement the Visitor pattern in C++:

```cpp
class Element;

class Visitor {
public:
    virtual ~Visitor() {}
    virtual void visit(Element& element) = 0;
};

class Element {
public:
    virtual ~Element() {}
    virtual void accept(Visitor& visitor) = 0;
};

class ConcreteElement1 : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

class ConcreteElement2 : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

class ConcreteVisitor : public Visitor {
public:
    void visit(Element& element) override {
        std::cout << "Visited an element" << std::endl;
    }

    void visit(ConcreteElement1& element) {
        std::cout << "Visited a ConcreteElement1" << std::endl;
    }

    void visit(ConcreteElement2& element) {
        std::cout << "Visited a ConcreteElement2" << std::endl;
    }
};
```

In this example, we define an `Element` interface that defines the `accept` method, which takes a `Visitor` object as a parameter. We also define a `Visitor` interface that defines the `visit` method, which is called when the `accept` method is called on an `Element`.

We also define two concrete `Element` classes (`ConcreteElement1` and `ConcreteElement2`) and a concrete `Visitor` class (`ConcreteVisitor`).

To use the Visitor pattern, you would first create an instance of the `Visitor` class, and then call the `accept` method on one or more `Element` objects, passing the `Visitor` object as a parameter:

```cpp
ConcreteVisitor visitor;
ConcreteElement1 element1;
ConcreteElement2 element2;

element1.accept(visitor);
element2.accept(visitor);
```

This would call the appropriate `visit` method on the `ConcreteVisitor` object, depending on the type of `Element` that was passed to the `accept` method.

The Visitor pattern can be useful in situations where you need to perform an operation on a group of objects that have different types or structures. It can also be useful when you need to add new operations to an existing set of classes without modifying those classes.

Here's an image showing the structure of the Visitor pattern:

![Visitor Pattern Structure](https://refactoring.guru/images/patterns/content/visitor/visitor.png)
Retrieved from [Refactoring.Guru](https://refactoring.guru/design-patterns/visitor/cpp/example#lang-features)