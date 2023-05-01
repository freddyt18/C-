#include <iostream>
#include <vector>
using namespace std;


#include "School.h"
using namespace S;

int main() {
    Classroom A201("A201", 2, 5, "Modern", "Steel");
    A201.display();

    cout << endl;

    School CADT(
        100, 
        "CADT", 
        "ABC #123 12011 Phnom Penh Cambodia", 
        {
            "Computer Science",
            "E-Commerce",
            "Telecommunication and Networking"
        },
        5,
        "Contemporary",
        "Glass"
    );

    CADT.display();

    return 0;
}