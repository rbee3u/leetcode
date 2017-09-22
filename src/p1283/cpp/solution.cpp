class Solution {
public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        auto lo = 1, hi = *max_element(nums.begin(), nums.end()) + 1;
        while (lo < hi) {
            auto md = lo + (hi - lo) / 2, sum = 0;
            for (auto x : nums) {
                sum += (x + md - 1) / md;
            }
            (sum > threshold) ? (lo = md + 1) : (hi = md);
        }
        return lo;
    }
};
