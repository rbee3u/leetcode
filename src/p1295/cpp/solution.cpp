class Solution {
public:
    int findNumbers(vector<int> &nums) {
        int result = 0;
        for (auto x : nums) {
            auto length = to_string(x).length();
            if (length % 2 == 0) result++;
        }
        return result;
    }
};
