#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <functional>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> tails;
        tails[0] = -1;
        int curr = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i] * 2 - 1;
            auto prev = tails.find(curr);
            if (prev != tails.end()) {
                result = std::max(result, i - prev->second);
            } else {
                tails[curr] = i;
            }
        }
        return result;
    }
};
