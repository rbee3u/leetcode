#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int> &nums, int target) {
        int first = 0, last = int(nums.size()) - 1;
        while (first < last && nums[first] == nums[last]) last--;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] == target) return mid;
            if (nums[first] <= nums[mid]) {
                (nums[first] <= target && target < nums[mid]) ? (last = mid - 1) : (first = mid + 1);
            } else {
                (nums[mid] < target && target <= nums[last]) ? (first = mid + 1) : (last = mid - 1);
            }
        }
        return -1;
    }
};
