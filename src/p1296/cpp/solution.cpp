class Solution {
public:
    bool isPossibleDivide(vector<int> &nums, int k) {
        auto n = int(nums.size());
        if (n % k != 0) return false;
        map<int, int> count;
        for (auto num : nums) {
            count[num]++;
        }
        while (n >= k) {
            auto start = count.begin()->first;
            for (int d = 0; d < k; d++) {
                if (count.find(start + d) == count.end()) {
                    return false;
                }
                if (--count[start + d] == 0) {
                    count.erase(start + d);
                }
            }
            n -= k;
        }
        return n == 0;
    }
};
