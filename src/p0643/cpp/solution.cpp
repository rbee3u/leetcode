#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double result = -1e11, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) total -= nums[i - k];
            total += nums[i];
            if (i + 1 >= k) {
                result = max(result, total / k);
            }
        }
        return result;
    }
};

