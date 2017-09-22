class Solution {
public:
    vector<int> nums;

    Solution() {
        queue<int> q;
        for (int x = 1; x <= 9; x++) {
            q.push(x);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int y = x * 10 + x % 10 + 1;
            if (x % 10 < 9 && y <= 1e9) {
                q.push(y);
                nums.push_back(y);
            }
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        auto lb = lower_bound(nums.begin(), nums.end(), low);
        auto ub = upper_bound(nums.begin(), nums.end(), high);
        return vector<int>(lb, ub);
    }
};
