#include <iostream>

#define DEBUG // Define macro for conditional compilation

int main() {
  #ifdef DEBUG // If DEBUG is defined, print debugging message
    std::cout << "Debugging message" << std::endl;
  #endif

  std::cout << "Normal message" << std::endl;
  return 0;
}


/**
 * In this example, we define a macro DEBUG using the #define directive. We then use the #ifdef directive to check if the macro is defined, and if it is, we print a debugging message. 
 * 
 * This allows us to easily enable or disable debugging output during development.
**/
void NOTE(){};