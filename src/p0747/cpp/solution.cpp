#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int index = -1, first = -1, second = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > first) {
                second = first;
                first = nums[i];
                index = i;
            } else if (nums[i] > second) {
                second = nums[i];
            }
        }
        if (first >= second * 2) {
            return index;
        } else {
            return -1;
        }
    }
};
