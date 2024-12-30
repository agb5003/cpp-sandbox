#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> output(std::vector<int> input) {
	std::vector<std::pair<int, int>> uniqueElements;
	return { 1, 0 };
}

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::vector<std::pair<int, int>> uniqueElements;
    std::vector<int> result;

    for (int num : nums) {
        // Check if current element is unique or if it's already in the tracker vector
        auto it = std::find_if(uniqueElements.begin(), uniqueElements.end(), [num](const auto& pair) {
            return pair.first == num;
            });

        if (it != uniqueElements.end()) {
            it->second++;
        }
        else {
            uniqueElements.push_back({ num, 1 });
        }
    }

    // Sort occurences of unique elements
    std::sort(uniqueElements.begin(), uniqueElements.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    for (int i = 0; i < k; i++) {
        result.push_back(uniqueElements[i].first);
    }

    return result;
}

int main() {
	//output({1, 2, 2, 4, 6, 6, 3, 3, 3});

	std::vector<int> nums = { 1, 1, 2, 2, 3, 4, 5, 6 };

    int k = 2;
    std::vector<int> result = topKFrequent(nums, k);
    for (int key : result) {
        std::cout << std::to_string(key) << std::endl;
    }
}