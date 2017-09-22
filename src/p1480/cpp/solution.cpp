class Solution {
public:
    std::vector<int> runningSum(const std::vector<int> &nums) {
        std::vector<int>::size_type n = nums.size();
        std::vector<int> sums(n);
        int sum = 0;
        for (std::vector<int>::size_type i = 0; i < n; i++) {
            sum += nums[i];
            sums[i] = sum;
        }
        return sums;
    }
};
