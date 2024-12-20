#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isAnagram(std::string a, std::string b) {
    if (a.size() != b.size()) { return false; }

    // std::sort does not return a sorted container.
    // newContainer = std::sort(...) does not work. It works in place.
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    return a == b;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> output;
    while (strs.size() > 0) {
        output.push_back(std::vector<std::string> {strs[0]}); // Copy element at the start into output
        strs.erase(strs.begin()); // Erase element at the start of strs
        // Iterate through rest of strs
        for (auto comparedIterator = strs.begin(); comparedIterator != strs.end();) {
            if (isAnagram(*comparedIterator, output.back()[0])) {
                output.back().push_back(*comparedIterator); // If an anagram is found, add it to the output
                strs.erase(comparedIterator); // Erase the matching anagram also from strs
            } else {
                comparedIterator++;
                // IMPORTANT: Notice that the for loop does not increment the iterator in its
                // declaration. Therefore, this else clause is needed to increment the iterator
                // if a match is not found. This way, the program would not be stuck checking
                // the same element over and over again.
            }
        }
    }
    return output;
}

int main() {
    std::vector<std::string> input;
    std::string input;
    int i = 1;
    while (input != "") {
        std::cout << "Enter word #" << std::to_string(i) << " (enter without typing to finalize): ";
        std::cin >> input;
    }
    std::vector<std::vector<std::string>> output = groupAnagrams(test);
    std::cout << '{';
    for (auto it = output.begin(); it != output.end(); it++) {
        std::cout << '{';
        for (auto it1 = (*it).begin(); it1 != (*it).end(); it1++) {
            std::cout << *it1;
            if (it1 != (*it).end() - 1) {std::cout << ", ";}
        }
        std::cout << '}';
        if (it != output.end() - 1) {std::cout << ", ";}
    }
    std::cout << '}' << std::endl;

    return 0;
}
