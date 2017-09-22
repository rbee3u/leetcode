class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0) return false;
        unordered_set<int> sets;
        int length = nums.size();
        for (int i=0; i < length; ++i) {
            if (i > k) {
                sets.erase(nums[i-k-1]);
            }
            if (sets.find(nums[i]) == sets.end()) {
                sets.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
