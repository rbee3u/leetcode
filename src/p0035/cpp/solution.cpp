#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        size_t begin = 0, end = nums.size();
        while (begin < end) {
            auto mid = begin + (end - begin) / 2;
            (nums[mid] < target) ? (begin = mid + 1) : (end = mid);
        }
        return int(begin);
    }
};
