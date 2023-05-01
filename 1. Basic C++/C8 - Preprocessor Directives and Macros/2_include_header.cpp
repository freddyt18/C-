#include <iostream>
#include "MyHeader.h"

int main() {
  int x = 2;
  int y = 3;
  int sum = add(x, y);
  std::cout << "The sum of " << x << " and " << y << " is " << sum << std::endl;
  return 0;
}

// MyHeader.cpp
int add(int a, int b) {
  return a + b;
}


/**
 * In this example, we use the #include directive to include the header file MyHeader.h in our source file MySource.cpp. 
 * 
 * This allows us to use the function add defined in MyHeader.cpp in our main program. 
 * 
 * We also use the #pragma once directive in MyHeader.h to ensure that the header file is only included once, even if it is included in multiple source files. 
 */
void NOTE(){};