class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0; do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int find=0; do {
            find = nums[find];
            slow = nums[slow];
        } while (find != slow);
        return find;
    }
};
