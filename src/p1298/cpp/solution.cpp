class Solution {
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes, vector<int> &initialBoxes) {
        auto n = int(status.size());
        vector<bool> candidates(n, false);
        for (auto box : initialBoxes) {
            candidates[box] = true;
        }
        int result = 0, i;
        for (;;) {
            for (i = 0; i < n; i++) {
                if (candidates[i] && status[i] == 1) {
                    break;
                }
            }
            if (i == n) {
                break;
            }
            result += candies[i];
            status[i] = 2;
            for (auto box : containedBoxes[i]) {
                candidates[box] = true;
            }
            for (auto key : keys[i]) {
                if (status[key] == 0) status[key] = 1;
            }
        }
        return result;
    }
};
