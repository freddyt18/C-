#include <iostream>
#include <vector>

class Shape;
class Circle;
class Square;
class Triangle;

class Visitor {
public:
    virtual ~Visitor() {}
    virtual void visit(Circle& shape) = 0;
    virtual void visit(Square& shape) = 0;
    virtual void visit(Triangle& shape) = 0;
};

class Shape {
public:
    virtual ~Shape() {}
    virtual void accept(Visitor& visitor) = 0;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getRadius() const { return radius_; }
private:
    double radius_;
};

class Square : public Shape {
public:
    Square(double length) : length_(length) {}
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getLength() const { return length_; }
private:
    double length_;
};

class Triangle : public Shape {
public:
    Triangle(double base, double height) : base_(base), height_(height) {}
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
    double getBase() const { return base_; }
    double getHeight() const { return height_; }
private:
    double base_;
    double height_;
};

class AreaVisitor : public Visitor {
public:
    AreaVisitor() : totalArea_(0) {}
    void visit(Circle& shape) override {
        double area = 3.14159 * shape.getRadius() * shape.getRadius();
        totalArea_ += area;
    }
    void visit(Square& shape) override {
        double area = shape.getLength() * shape.getLength();
        totalArea_ += area;
    }
    void visit(Triangle& shape) override {
        double area = 0.5 * shape.getBase() * shape.getHeight();
        totalArea_ += area;
    }
    double getTotalArea() const { return totalArea_; }
private:
    double totalArea_;
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(3.0));
    shapes.push_back(new Square(2.0));
    shapes.push_back(new Triangle(4.0, 5.0));

    AreaVisitor areaVisitor;
    for (Shape* shape : shapes) {
        shape->accept(areaVisitor);
    }
    std::cout << "Total area: " << areaVisitor.getTotalArea() << std::endl;

    // Clean up
    for (Shape* shape : shapes) {
        delete shape;
    }
    return 0;
}
