#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        size_t n = nums.size(), m = 1, x;
        unordered_map<int, size_t> dict;
        for (auto v : set<int>(nums.begin(), nums.end()))
            dict[v] = m++;
        vector<int> result(n, 0), bit(m, 0);
        for (auto i = nums.size(); i-- > 0;) {
            for (x = dict[nums[i]] - 1; x > 0; x -= x & (-x))
                result[i] += bit[x];
            for (x = dict[nums[i]] - 0; x < m; x += x & (-x))
                bit[x]++;
        }
        return result;
    }
};
