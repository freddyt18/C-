#include <iostream>
#include <vector>
#include <string>


class Move_Vector {
    public:
        Move_Vector(std::string* ID){
            this->ID = ID;
            std::cout << "Default Constructor with ID " << *ID << std::endl;
        }

        Move_Vector(Move_Vector&& other){
            std::cout << "Moving Constructor with ID " << *ID << std::endl;

            this->ID = other.ID;
            this->ID = nullptr;
        }

        Move_Vector& operator=(Move_Vector&& other){
            if(this != &other){
                delete[] ID;

                ID = other.ID;
                other.ID = nullptr;
            }

            std::cout << "Moving Assignment Operator" << std::endl;

            return *this;
        }

        ~Move_Vector(){
            std::cout << "Destructor Called" << std::endl;

        }
        
        void display(){
            std::cout << "ID: " << ID << std::endl;
        }
    
    private:
        std::string DEFAULT = "DEFAULT";
        std::string* ID = &DEFAULT;
};


int main(){
    
    std::vector<std::string*> ID;
    std::vector<Move_Vector> Example;
    
    for(int i = 0; i < 5; i++){
        ID.push_back(
            new std::string(
                "Object-" + std::to_string(i)
            )
        );
    }

    for(auto each : ID){
        std::cout << "Pushed " << each << std::endl;
        Example.push_back(Move_Vector(each));
        std::cout << "Done" << std::endl;
    }

    Example[0] = std::move(Example[1]);
    Example[2] = std::move(Example[3]);

    Example[2].display();

    return 0;
}