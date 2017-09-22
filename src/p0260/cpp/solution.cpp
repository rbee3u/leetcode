#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int d = 0, x = 0, y = 0;
        for (auto e : nums) {
            d ^= e;
        }
        d = d & (-d);
        for (auto e : nums) {
            (d & e) ? (x ^= e) : (y ^= e);
        }
        return {x, y};
    }
};
