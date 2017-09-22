#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, int> counts, begs, ends;
        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
            if (begs.count(nums[i]) == 0) {
                begs[nums[i]] = i;
            }
            ends[nums[i]] = i;
        }
        unordered_set<int> vals; int prev = - 1;
        for (auto &count : counts) {
            if (count.second > prev) {
                vals.clear(); prev = count.second;
                vals.insert(count.first);
            } else if (count.second == prev) {
                vals.insert(count.first);
            }
        }
        int result = INT_MAX;
        for (auto &beg : begs) {
            if (vals.count(beg.first) == 0) continue;
            int diff = ends[beg.first] - beg.second + 1;
            result = min(result, diff);
        }
        return result;
    }
};
