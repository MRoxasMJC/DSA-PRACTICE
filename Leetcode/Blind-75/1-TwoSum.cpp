#include <iostream>
#include <vector>
#include <unordered_map>


// my solution O(N^2)
// std::vector<int> twoSum(std::vector<int>& nums, int target) {
//     std::vector<int> indices;
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = i + 1; j < nums.size(); j++) {
//             if ((nums.at(i) + nums.at(j) == target)) {
//                 indices.push_back(i);
//                 indices.push_back(j);
//                 return indices;
//             }
//         }
//     }
//
//     return indices;
// }

// someone elses solution: O(N)
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> mp; // use a hash map to map value -> index
    for (int i = 0; i < nums.size(); i++) {
        int x = target - nums[i]; // the number we are looking for in the hashmap;
        if (mp.find(x) != mp.end()) {
            return { mp[x], i };
        }
        mp[nums[i]] = i; // value -> index
    }
    return {};
}

int main() {
    std::vector<int> nums = {3, 2, 4};
    std::vector<int> output;

    output = twoSum(nums, 6);

    for (int i = 0; i < output.size(); i++) {
        std::cout <<  output.at(i) << " " ;
    }
    std::cout << std::endl;

    return 0;
}