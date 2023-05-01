#include <iostream>
#include <string>


namespace C{
    class Car {
        private:
            int speed;
            int gear;
            int accelerate_time;
            int brake_time;
            std::string name;

        public:
            Car(std::string name) {
                this->name = name;
                speed = 0;
                gear = 0;
                accelerate_time = 0;
                brake_time = 0;
                std::cout << "A new car has been created!" << std::endl;
            }
            ~Car() {
                std::cout << "The car has been destroyed!" << std::endl;
            }
            void accelerate() {
                accelerate_time++;
                speed += 10;
            }
            void brake() {
                brake_time++;
                speed -= 10;
            }
            void changeGear(int newGear) {
                gear = newGear;
            }
            void data(){
                std::cout << std::endl;
                std::cout << "This car is a " << name << std::endl;
                std::cout << "The speed of the car is " << speed << std::endl;
                std::cout << "The gear of the car is " << gear << std::endl;       
                std::cout << "The car braked " << brake_time << " time(s)" << std::endl;       
                std::cout << "The car has accelerated " << accelerate_time << " times(s)" << std::endl;       
                std::cout << std::endl;
            }
    };
}