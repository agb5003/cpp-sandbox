#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int romanToInteger(std::string roman) {
    std::unordered_map<char, int> map = {{'V', 5}, {'L', 50}, {'D', 500}, {'M', 1000}}; int result = 0;

    for (int i = 0; i < roman.size(); i++) {
        switch (roman[i]) {
            case 'I':
                switch (roman[i+1]) {
                    case 'V':
                        result += 4;
                        i++;
                        break;
                    case 'X':
                        result += 9;
                        i++;
                        break;
                    default:
                        result += 1;
                        break;
                }
                break;
            case 'X':
                switch (roman[i+1]) {
                    case 'L':
                        result += 40;
                        i++;
                        break;
                    case 'C':
                        result += 90;
                        i++;
                        break;
                    default:
                        result += 10;
                        break;
                }
                break;
            case 'C':
                switch (roman[i+1]) {
                    case 'D':
                        result += 400;
                        i++;
                        break;
                    case 'M':
                        result += 900;
                        i++;
                        break;
                    default:
                        result += 100;
                        break;
                }
                break;
            default:
                result += map[roman[i]];
        }
    }

    return result;
}

int main() {
    std::string roman;
    std::cout << "Enter the roman numeral to convert: " << std::endl;
    std::cin >> roman;
    std::cout << "That roman numeral is equal to " <<romanToInteger(roman) << '.' << std::endl;
}
