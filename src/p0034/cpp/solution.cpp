#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result = {-1, -1};
        size_t begin, end, mid;
        for (begin = 0, end = nums.size(); begin < end;) {
            mid = begin + (end - begin) / 2;
            (nums[mid] < target) ? (begin = mid + 1) : (end = mid);
        }
        if (begin == nums.size() || nums[begin] != target) return result;
        result[0] = static_cast<int>(begin);
        for (begin = 0, end = nums.size(); begin < end;) {
            mid = begin + (end - begin) / 2;
            (nums[mid] <= target) ? (begin = mid + 1) : (end = mid);
        }
        result[1] = static_cast<int>(--end);
        return result;
    }
};
