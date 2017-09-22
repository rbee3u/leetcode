class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret=0, prev, len=nums.size();
        if (len > 0) prev = nums[0] + 1;
        for (int i=0; i < len; ++i) {
            if (nums[i] != prev) {
                nums[ret++] = nums[i];
                prev = nums[i];
            }
        }
        return ret;
    }
};
