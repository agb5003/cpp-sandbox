#include <cstring>
#include <string>
#include <iostream>

int main() {
    const char* myString = "I am a C-style string.";
    for(int i = 0; i < strlen(myString); i++) {
        std::string cppString = std::string(myString, i, strlen(myString));
        std::cout << cppString << std::endl;
    }

}
