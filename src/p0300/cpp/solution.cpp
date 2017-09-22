class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size(), ret=0; vector<int> stk(len+1);
        for (auto x : nums) {
            int low=1, high=ret; for (; low <= high; ) {
                int mid = low + (high - low) / 2;
                (stk[mid]<x) ? (low=mid+1) : (high=mid-1);
            }
            stk[low] = x; (ret < low) && (ret = low);
        }
        return ret;
    }
};
