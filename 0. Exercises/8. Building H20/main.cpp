#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class H2O {
public:
    H2O() {
        // Set initial count of hydrogen and oxygen to zero.
        h_count = 0;
        o_count = 0;
    }
    

    void hydrogen(function<void()> releaseHydrogen) {

        /* 
            Lock the thread if there are already 2 hydrogen atoms
            or 1 oxygen atom present.
            This prevents the function from executing until the
            condition is met.
        */
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){ return h_count < 2 && o_count < 1; });

        // Increment count of hydrogen atoms.
        h_count++;

        // Release hydrogen atom.
        releaseHydrogen();
        
        /*  
            If there are already 2 hydrogen atoms and 1 oxygen atom present,
            reset the count of hydrogen and oxygen to zero.
            Then, notify all threads waiting on the condition variable.
        */
        if (h_count == 2 && o_count == 1) {
            h_count = 0;
            o_count = 0;
        }
        cv.notify_all();
    }

   
    void oxygen(function<void()> releaseOxygen) {
        
        /*  
            Lock the thread if there are not enough hydrogen atoms or
            there is already 1 oxygen atom present.
            This prevents the function from executing until the condition
            is met.
        */
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){ return h_count >= 2 && o_count < 1; });

        // Increment count of oxygen atoms.
        o_count++;

        // Release oxygen atom.
        releaseOxygen();

        /*  
            If there are already 2 hydrogen atoms and 1 oxygen atom present,
            reset the count of hydrogen and oxygen to zero.
            Then, notify all threads waiting on the condition variable.
        */        
        if (h_count == 2 && o_count == 1) {
            h_count = 0;
            o_count = 0;
        }
        cv.notify_all();
    }

private:
    mutex mtx;
    condition_variable cv;
    int h_count, o_count;
};

void h() {
    cout << "H";
}

void o() {
    cout << "O";
}

int main() {

    int amount_of_o = 0, amount_of_h = 0;

    cout << "Amount of Oxygen: "; cin >> amount_of_o;

    string water = "";
    
    for(int o = 0; o < amount_of_o; o++){
        water.append("O");
        water.append("H");
        water.append("H");
    }

    cout << "Input: " << water.c_str() << endl << endl;
    cout << "Multi-Thread Conditioned Processed Data" << endl;

    H2O h2o;
    vector<thread> threads;
    for (char c : water) {
        if (c == 'H') {
            threads.emplace_back(([&](){ h2o.hydrogen(h); }));
        } else {
            threads.emplace_back(([&](){ h2o.oxygen(o); }));
        }
    }
    for (auto& thread : threads) {
        thread.join();
    }
    cout << endl << endl;
    return 0;
}
