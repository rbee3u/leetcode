class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); assert(n > 1);
        vector<int> output(n, 1);
        for (int i=n-1; i; --i) {
            output[i-1] = nums[i]*output[i];
        }
        for (int i=0, acc=1; i < n; ++i) {
            output[i] *= acc; acc *= nums[i];
        }
        return output;
    }
};
