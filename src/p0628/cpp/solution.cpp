#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        int rfirst = INT_MAX, rsecond = INT_MAX;
        for (auto num : nums) {
            if (num > first) {
                third = second; second = first; first = num;
            } else if (num > second) {
                third = second; second = num;
            } else if (num > third) {
                third = num;
            }
            if (num < rfirst) {
                rsecond = rfirst; rfirst = num;
            } else if (num < rsecond) {
                rsecond = num;
            }
        }
        int result = INT_MIN;
        result = max(result, first * second * third);
        result = max(result, first * rsecond * rfirst);
        return result;
    }
};
