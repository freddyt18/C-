#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Building.h"
using namespace B;


namespace S {
    class School : public Building {
        private:
            int amount_of_students;
            string name;
            string address;
            vector<string> majors;

        public:
            School(int amount_of_students, string name, string address, vector<string> majors, int stories, string architecture_type, string material){

                // Building Variables
                setStories(stories);
                setArchitectureType(architecture_type);
                setMaterial(material);

                // School Variables
                this->amount_of_students = amount_of_students;
                this->name = name;
                this->address = address;
                this->majors = majors;
                
            };

            void display() {
                cout << "Building of the School Information:" << endl;
                cout << "  Stories: " << getStories() << endl;
                cout << "  Architecture Type: " << getArchitectureType() << endl;
                cout << "  Material: " << getMaterial() << endl;

                cout << "School Information:" << endl;
                cout << "  Amount of Students: " << amount_of_students << endl;
                cout << "  Name: " << name << endl;
                cout << "  Address: " << address << endl;

                cout << "  Majors: " << endl;
                for (string m : majors){
                    cout << "  \t• : " << m << endl;
                }
                
            }
    };

    class Classroom : public Building {
        private:

            // Classroom Variables
            string name;
            int floor;
            
        public:
            Classroom(string name, int floor, int stories, string architecture_type, string material){

                // Building
                setStories(stories);
                setArchitectureType(architecture_type);
                setMaterial(material);

                // Classroom
                this->name = name;
                this->floor = floor;

            };

            void display() {
                cout << "Building of the Classroom Information:" << endl;
                cout << "  Stories: " << getStories() << endl;
                cout << "  Architecture Type: " << getArchitectureType() << endl;
                cout << "  Material: " << getMaterial() << endl;

                cout << "Classroom Information:" << endl;
                cout << "  Name: " << name << endl;
                cout << "  Floor: " << floor << endl;
            }
    };

    class Student {
        private:
            string name;
            char sex;
            int age;
        
        public:
            Student(string name, char sex, int age){
                
                this->name = name;
                this->sex = sex;
                this->age = age;

            };
    };
};
