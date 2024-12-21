#include <iostream>
#include <string>

int main() {
    int numberA;
    int numberB;
    std::cout << "Enter number A: ";
    std::cin >> numberA;
    std::cout << "Enter number B: ";
    std::cin >> numberB;

    std::cout << "The sum of the two numbers is " << std::to_string(numberA + numberB) << std::endl;
    std::cout << "The difference of the two numbers is " << std::to_string(numberA - numberB) << std::endl;
}
