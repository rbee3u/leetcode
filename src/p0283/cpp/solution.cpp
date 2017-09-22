class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        for (; j < n; ++j) if (nums[j]) {
            if (i != j) {
                nums[i] = nums[j];
                nums[j] = 0;
            } ++i;
        }
    }
};
