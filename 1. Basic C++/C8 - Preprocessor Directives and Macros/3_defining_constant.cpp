#include <iostream>

#define PI 3.14159 // Define a constant

int main() {
  double radius = 2.5;
  double area = PI * radius * radius;
  std::cout << "The area of a circle with radius " << radius << " is " << area << std::endl;
  return 0;
}


/**
 * In this example, we define a constant PI using the #define directive. 
 * 
 * We then use this constant to calculate the area of a circle with a given radius. 
 * 
 * This allows us to avoid hard-coding the value of pi in our program and makes it easier to change the value if needed.
 */
void NOTE(){};