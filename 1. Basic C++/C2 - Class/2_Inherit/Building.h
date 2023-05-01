#include <iostream>
#include <string>
using namespace std;

namespace B {
    class Building {
        private:
            int stories;
            string architecture_type;
            string material;

        public:
            Building(){

                this->stories = 0;
                this->architecture_type = "";
                this->material = "";

            };

            void setStories(int stories) {
                this->stories = stories;
            }

            void setArchitectureType(string architecture_type) {
                this->architecture_type = architecture_type;
            }

            void setMaterial(string material) {
                this->material = material;
            }

            
            int getStories() const {
                return stories;
            }

            string getArchitectureType() const {
                return architecture_type;
            }

            string getMaterial() const {
                return material;
            }
    };
};