#include <iostream>

struct MyStruct {
    int var;
};

void getValueFromUser() {
    if (true && true) {
        std::cout << "True" << std::endl;
    }
}

int main() {
    getValueFromUser();
    
    return 0;
}