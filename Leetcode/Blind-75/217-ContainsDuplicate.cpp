#include <iostream>
#include <vector>
#include <unordered_map>

// my solution: 54ms Runtime O(n)
bool containsDuplicate(std::vector<int>& nums) {

    // maybe we can use an unordered map and store items in it as we iterate through

    std::unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums.at(i)) != m.end()) {
            return true;
        } else {
            m[nums.at(i)] = i;
        }
    }

    return false;
}

int main() {
    std::vector<int> nums1 = {1,2,3,1};
    std::vector<int> nums2 = {1, 2, 3, 4};
    std::vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    std::cout << containsDuplicate(nums1) << std::endl; // should be true
    std::cout << containsDuplicate(nums2) << std::endl; // should be false
    std::cout << containsDuplicate(nums3) << std::endl; // should be true

    return 0;
}