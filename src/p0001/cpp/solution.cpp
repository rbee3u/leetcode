class Solution {
public:
    static vector<int> twoSum(const vector<int> &nums, int target) {
        unordered_map<int, vector<int>::size_type> dict;

        for (vector<int>::size_type j = 0; j < nums.size(); j++) {
            if (auto i = dict.find(target - nums[j]); i != dict.end()) {
                return {int(i->second), int(j)};
            }

            dict[nums[j]] = j;
        }

        return {};
    }
};
