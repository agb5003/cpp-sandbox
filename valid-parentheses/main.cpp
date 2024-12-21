#include <iostream>
#include <vector>
#include <string>

bool isValid(std::string s) {
    std::vector<char> stack;
    for (char c : s) {
        std::cout << c << std::endl;
        switch (c) {
            case '{':
                stack.push_back('}');
            case '(':
                stack.push_back(')');
            case '[':
                stack.push_back(']');
            default:
                if (c != stack.back()) {
                    return false;
                } else {
                    stack.pop_back();
                }
        }
    }
    return true;
}

int main() {
    std::cout << isValid("()") << std::endl;

    return 0;
}
