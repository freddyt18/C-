#include <iostream>
#include <string>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    
    void setConfig(const std::string& config) {
        config_ = config;
    }
    
    std::string getConfig() const {
        return config_;
    }
    
private:
    Singleton() {
        std::cout << "Creating Singleton instance..." << std::endl;
    }
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    
    std::string config_;
};

int main() {
    // Get the Singleton instance and set its configuration
    Singleton& mySingleton = Singleton::getInstance();
    mySingleton.setConfig("myConfig");
    
    // Get the Singleton instance again and print its configuration
    Singleton& mySingleton2 = Singleton::getInstance();
    std::cout << mySingleton2.getConfig() << std::endl;

    
    return 0;
}
