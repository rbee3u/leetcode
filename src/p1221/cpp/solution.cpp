class Solution {
public:
    int balancedStringSplit(const string &s) {
        int result = 0, weight = 0;
        for (auto x : s) {
            if (x == 'L') {
                weight--;
            } else {
                weight++;
            }
            if (weight == 0) {
                result++;
            }
        }
        return result;
    }
};
