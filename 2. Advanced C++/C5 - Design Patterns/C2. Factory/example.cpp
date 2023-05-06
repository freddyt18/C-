#include <iostream>
#include <string>
#include <map>

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

int main() {
    std::map<std::string, Factory*> factoryMap;
    factoryMap["A"] = new FactoryA();
    factoryMap["B"] = new FactoryB();
    
    std::string input;
    std::cout << "Enter product type (A or B): ";
    std::cin >> input;
    
    Product* product = factoryMap[input]->createProduct();
    product->use();
    
    delete product;
    delete factoryMap["A"];
    delete factoryMap["B"];
}
