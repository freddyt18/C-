#include <iostream>
using namespace std;

#include "Car.h"
using namespace C;

int main(){
    Car lambo("Lambo");

    lambo.accelerate();
    lambo.brake();
    lambo.accelerate();
    lambo.brake();
    lambo.accelerate();

    lambo.data();

    return 0;
}