#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> counts;
        for (auto num : nums) counts[num]++;
        int result = 0;
        for (auto &count : counts) {
            if (k == 0) {
                result += count.second >= 2;
            } else {
                int another = count.first + k;
                result += counts.count(another) > 0;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    cout << sol.findPairs(nums, k) << endl;
    return 0;
}
