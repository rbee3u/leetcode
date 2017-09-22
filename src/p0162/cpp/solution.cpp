#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int first = 0, last = int(nums.size()) - 1;
        while (first < last) {
            auto left = first + (last - first) / 2, right = left + 1;
            (nums[left] < nums[right]) ? (first = right) : (last = left);
        }
        return first;
    }
};
