#include <iostream>
#include <string>
#include <cmath>

class operators {
    
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./main <number>" << std::endl;
        return 1;
    }
    int number = std::stod(argv[1]);

    std::cout << "The square of " << argv[1] << " is " << std::pow(number, 2) << std::endl;

    return 1;
}