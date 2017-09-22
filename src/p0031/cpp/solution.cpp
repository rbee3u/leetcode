class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        if (len < 2) return;
        int i=len-1, j=len-1;
        for (; i && nums[i-1]>=nums[i]; --i);
        if (0 == i) {
            reverse(&nums[0], &nums[len]);
            return;
        }
        for (--i; nums[i]>=nums[j]; --j);
        iter_swap(&nums[i], &nums[j]);
        reverse(&nums[i+1], &nums[len]);
    }
};

