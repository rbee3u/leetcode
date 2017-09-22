class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (len <= 1) return false;
        int tmp = nums[0];
        for (int i=1; i < len; ++i) {
            if (nums[i] == tmp) return true;
            tmp = nums[i];
        }
        return false;
    }
};
