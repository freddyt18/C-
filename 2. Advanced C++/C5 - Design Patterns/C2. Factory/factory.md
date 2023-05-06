# Factory Pattern

The Factory design pattern is another creational pattern that provides a way to create objects without specifying their exact class. Instead of creating objects directly, a factory method is used to create objects based on a set of input parameters.

Here's an example of how to implement the Factory pattern in C++:

```cpp
class Product {
public:
    virtual ~Product() {}
    virtual void use() = 0;
};

class ProductA : public Product {
public:
    void use() override {
        std::cout << "Using ProductA" << std::endl;
    }
};

class ProductB : public Product {
public:
    void use() override {
        std::cout << "Using ProductB" << std::endl;
    }
};

class Factory {
public:
    virtual ~Factory() {}
    virtual Product* createProduct() = 0;
};

class FactoryA : public Factory {
public:
    Product* createProduct() override {
        return new ProductA();
    }
};

class FactoryB : public Factory {
public:
    Product* createProduct() override {
        return new ProductB();
    }
};
```

In this example, we define a set of `Product` classes that implement a common interface for using the product, and a set of `Factory` classes that create instances of the products.

To use the Factory pattern, you would first select the appropriate `Factory` class based on the desired product, and then call the `createProduct` method to create the product instance:

```cpp
Factory* factory = new FactoryA(); // or FactoryB
Product* product = factory->createProduct();
product->use();
```

This would create an instance of `ProductA` (or `ProductB`) using the appropriate `Factory` class, and then call the `use` method on the product.

The Factory pattern can be useful in situations where you want to decouple the creation of objects from the code that uses them, or when you need to create objects dynamically based on input parameters. It can also be useful when you want to enforce a certain set of constraints on the objects that are created, such as limiting the number of objects that can be created, or enforcing certain initialization parameters.


Here's an image showing the structure of the Factory pattern:

![Factory Pattern](https://4.bp.blogspot.com/-8XUeiQaqK4Q/Ur_4oDzc9QI/AAAAAAAAFnY/_Jrh9ai5ByM/s1600/factory_2.png)
Retrieved from: [Source](https://4.bp.blogspot.com/-8XUeiQaqK4Q/Ur_4oDzc9QI/AAAAAAAAFnY/_Jrh9ai5ByM/s1600/factory_2.png)