#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Asking for input
    std::string x;

    std::cout << "Enter a string: ";
    std::cin >> x;
    

    // Open a file for writing
    std::ofstream outputFile("example.txt");

    if (outputFile.is_open()) {
        // Write some data to the file
        outputFile << x << "\n";
        outputFile << "Hello, world!\n";
        outputFile << "This is an example file.\n";
        outputFile << "Goodbye!\n";

        // Close the file
        outputFile.close();
    }

    // Open the same file for reading
    std::ifstream inputFile("example.txt");

    if (inputFile.is_open()) {
        // Read the data from the file and output it to the console
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }

        // Close the file
        inputFile.close();
    }

    return 0;
}
