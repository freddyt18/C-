#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <mutex>
#include <map>

using namespace std;

auto total_value = 0;
auto total_rvalue = 0;
std::mutex mtx;


template<typename T>
void sort_vector_value(int thread_idx, T& v){
    auto start_time = chrono::high_resolution_clock::now();

    sort(v.begin(), v.end());

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

    std::lock_guard<std::mutex> guard(mtx);
    total_value += duration.count();
}

template<typename T>
void sort_vector(int thread_idx, T&& v)
{
    auto start_time = chrono::high_resolution_clock::now();

    sort(
        forward<T>(v).begin(), 
        forward<T>(v).end()
    );

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

    std::lock_guard<std::mutex> guard(mtx);
    total_rvalue += duration.count();
}


void fill(vector<vector<int>>& v, int size)
{
    vector<int> dump_data;

    for(int i = 0; i < 1000; i++){
        dump_data.push_back(i);
    }

    for(int i = 0; i < size; i++){
        v.push_back(dump_data);
    }
}

int main()
{
    map<int, vector<int>> average;
    
    int size = 10000;
    int o_size = size;

    vector<vector<int>> v1;
    fill(v1, size);

    vector<vector<int>> vector_value = v1;

    int* y = &size;
    *y -= 1;

    vector<thread> threads;

    for(int _t = 0; _t < 5; _t++){
        threads.push_back(thread([&](){
            try {
                while(*y > 2){
                    sort_vector(
                        _t,
                        v1[*y]
                    );
                    sort_vector_value(_t, vector_value[*y]);

                    if(*y % 500 == 0){
                        average[o_size - *y] = {total_value / (o_size * 5), total_rvalue / (o_size * 5)};
                    }

                    --*y;
                }
            } catch (const std::exception& e) {
                std::cerr << e.what() << '\n';
            }
        }));

    }
    
    for(auto& t : threads){
        t.join();
    }


    std::cout << "Element | Value | R-Value\n";
    for(auto& [key, value] : average){
        std::cout << key << " | " << value[0] << "ns : " << value[1] << "ns" << endl;
    }


    
    return 0;
}

/* 
    
    The program often needs to be run multiple times in order to get this result.
    For some reasons, the first few runs doesn't give any result at all.

    Element | Value | R-Value
    500 | 1207ns : 824ns
    1000 | 2439ns : 1699ns
    1500 | 3784ns : 2709ns
    2000 | 5110ns : 3704ns
    2500 | 6448ns : 4717ns
    3000 | 7680ns : 5639ns
    3500 | 9000ns : 6577ns
    4000 | 10359ns : 7563ns
    4500 | 11578ns : 8477ns
    5000 | 12838ns : 9434ns
    5500 | 14115ns : 10386ns
    6000 | 15506ns : 11481ns
    6500 | 16847ns : 12383ns
    7000 | 18109ns : 13233ns
    7500 | 19442ns : 14183ns
    8000 | 20655ns : 15033ns
    8500 | 21955ns : 15955ns
    9000 | 23364ns : 16958ns
    9500 | 24589ns : 17868ns
*/