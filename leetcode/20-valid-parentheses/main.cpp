#include <iostream>
#include <vector>
#include <string>

bool isValid(std::string s) {
// Edge case: odd number of chars in string, or only one char in string
    if (s.size()%2 != 0) { return false; }
    std::vector<char> stack;
    bool closing = false;
    for (char c : s) {
        switch (c) {
            case '(':
                stack.push_back(')');
                break;
            case '[':
                stack.push_back(']');
                break;
            case '{':
                stack.push_back('}');
                break;
            default:
                // Edge case: no opening brackets before closing starts
                if (stack.size() == 0) { return false; }
                if (c == stack.back()) {
                    closing = true;
                    stack.pop_back();
                } else { return false; }
        }
    }
    // Edge case: when the string ends before stack is empty
    if (stack.size() != 0) { return false; }
    return true;
}

int main(int argc, char* argv[]) {
    std::cout << (isValid(argv[1]) ? "Valid parentheses." : "Invalid parentheses.") << std::endl;

    return 0;
}
