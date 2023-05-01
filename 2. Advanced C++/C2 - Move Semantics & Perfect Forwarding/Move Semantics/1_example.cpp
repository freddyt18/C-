/**
 * In this example, we define a class `Example` with a move constructor and a move assignment operator. We also define a function `createExample` that returns a temporary object of type `Example`.
 * 
 * In the `main` function, we create several instances of `Example` and move them using `std::move`. We also push a temporary object of type `Example` onto a `std::vector`, which moves the object into the container instead of copying it.
 * 
 * The output of this program shows that the move constructor and move assignment operator are called when objects are moved, while the destructor is called when objects are destroyed.
 * 
 * Move semantics can greatly improve performance when dealing with large objects or containers, as it allows for the transfer of ownership of resources instead of copying them. 
 **/
void NOTE(){};

#include <iostream>
#include <vector>

class Example {
  public:
    Example(char ID) {
      this->ID = ID;
      std::cout << ID << std::endl;
      std::cout << "Default constructor" << std::endl;
      data = new int[1000000];
    }

    // Move constructor
    /**
     * This is a move constructor in C++ that moves the data from another object and sets its data
    * pointer to null.
    * 
    * @param other other is an rvalue reference to an object of type Example. It is used in the move
    * constructor to move the data from the other object to the current object being constructed. After
    * the move, the other object's data pointer is set to nullptr to indicate that it no longer owns the
    * data.
    */
    Example(Example&& other) {
      std::cout << "Move constructor" << std::endl;

      data = other.data;
      ID = other.ID;
      
      other.data = nullptr;
    
    }
  
    // Move assignment operator
    /**
     * This is a move assignment operator that deletes the current data and assigns the data of another
    * object to it.
    * 
    * @return The move assignment operator is returning a reference to the current object, which is
    * being modified and moved. The returned reference is dereferenced using the * operator to access
    * the modified object.
    */
    Example& operator=(Example&& other) {
      std::cout << "Move assignment operator" << std::endl;

      if (this != &other) {
          delete[] data;
          data = other.data;
          ID = other.ID;
      
          std::cout << ID << " is set to nullptr" << std::endl;
          other.data = nullptr;
      }
      
      return *this;
    }
  
    ~Example() {
      std::cout << "Destructor " << this->ID << std::endl;
      
      delete[] data;
    }
  
private:
    char ID;
    int* data;
};

/**
 * The function creates and returns an instance of the Example class.
 * 
 * @return An instance of the class Example, created using the default constructor.
 */
Example createExample(char ID) {
  return Example{ID};
}


int main() {
    Example a{'a'};
    Example b{std::move(a)}; // Move constructor
    
    Example c{'c'};
    c = std::move(b); // Move assignment operator
    
    std::vector<Example> v;
    v.push_back(Example{'v'}); // Move constructor
    
    Example d{createExample('d')}; // Move constructor
    
    return 0;
}

