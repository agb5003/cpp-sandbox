#include <iostream>

void Log(const char* message) {
    std::cout << message << std::endl;
}

void SomeFunc() {
    Log("Initialized logging.");
}