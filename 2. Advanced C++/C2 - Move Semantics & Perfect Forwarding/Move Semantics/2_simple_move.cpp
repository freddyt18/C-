#include <iostream>
#include <string>

using namespace std;

class Test {
    public:

        // Default Constructor
        Test(string ID){
            
            this->ID = ID;

            cout << ID << "'s Default Constructor" << endl;
        }

        // Move constructor
        Test(Test &&other){
            cout << "Moving " << this->ID << "'s Constructor from " << other.ID << endl;
            
            this->data = other.data;
            this->ID = other.ID;

        }

        Test &operator=(Test &&other){
            if (this != &other) {

                data = other.data;
                ID = other.ID;
            
            }

            cout << "Moving " << this->ID << "'s assignment operator." << endl;

            return *this;

        }

        ~Test(){
            cout << ID << "'s Destructor" << endl;
        }


    private:
        string ID = "DEFAULT";
        int data = 0;
};


int main(){

    Test a{"A"};

    // Moving the constructor
    Test b{move(a)};

    // Moving the assignment operator
    Test c{"C"};
    c = move(a);

    return 0;
}