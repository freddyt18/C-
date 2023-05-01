#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <map>
#include <thread>

class School {
    public:
        School(){
            std::string m = "";
            for(int x=0; x<10; x++){
                for(int i=0; i<10; i++){
                    for(int j=0; j<10; j++){
                        m += "Major";
                    }
                    majors.push_back(m + std::to_string(i));
                }
            }

            for(int i=0; i<10; i++){
                category.push_back(majors);
            }

            // std::cout << "Default Constructor" << std::endl;
        }

        School(const School& other){
            
            this->category = other.category;
            this->majors = other.majors;

            // std::cout << "Copy Constructor" << std::endl;
        }

        School(School&& other){

            this->category = std::move(other.category);
            this->majors = std::move(other.majors);

            // std::cout << "Move Constructor" << std::endl;
        }

        // ~School(){
        //     std::cout << "Destructor" << std::endl;
        // }

    private:
        std::vector<std::string> majors;
        std::vector<std::vector<std::string>> category;
};

std::map<int, std::vector<int>> copy_move_value;
std::vector<std::thread> tr;
int x = 10000;

void worker(int T){
    while(x > 0){
        std::cout << "T" << T <<" - Iteration: " << x << std::endl;

        int copy;
        int move;

        auto start = std::chrono::high_resolution_clock::now();
        School a{};
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        // std::cout << "Instance a's Initiation Execution time: " << duration.count() << " micro s\n";
        
        start = std::chrono::high_resolution_clock::now();
        School b{a};
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        // std::cout << "Copying constructor a -> b Execution time: " << duration.count() << " micro s\n";
        copy = duration.count();

        start = std::chrono::high_resolution_clock::now();
        School c{std::move(a)};
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        // std::cout << "Moving constructor a -> c Execution time: " << duration.count() << " micro s\n";
        move = duration.count();

        copy_move_value[x] ={copy, move};

        x -= 1;
    }
};


int main(){

    for(int T = 0; T < 4; T++){
        tr.emplace_back(worker, T);
    }

    
    for(auto& x : tr){
        x.join();
    }
    
    auto avg_copy = 0;
    auto avg_move = 0;

    for(auto each = copy_move_value.begin(); each != copy_move_value.end(); ++each){
        // std::cout << "Copy:" << each->second[0] << "ns -> Move:" << each->second[1] << "ns" << std::endl;
    
        if (each == std::prev(copy_move_value.end())) break;

        avg_copy += (int) each->second[0];
        avg_move += (int) each->second[1];

    }

    avg_copy /= copy_move_value.size();
    avg_move /= copy_move_value.size();

    std::cout << "\nCopy VS Move constructor Execution time (Nanoseconds)\n";
    std::cout << "Average Copy: " << avg_copy << "ns \nAverage Move: " << avg_move << "ns\n\n";

    return 0;
}