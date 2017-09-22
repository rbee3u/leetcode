class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=0, len=nums.size();
        for (; j < len; ++j) if (nums[j] != val) {
            swap(nums[i], nums[j]); ++i;
        }
        return i;
    }
};
