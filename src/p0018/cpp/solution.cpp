class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        for (size_t i = 0; i + 3 < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            for (size_t j = i + 1; j + 2 < n; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                int sum2 = nums[i] + nums[j];
                for (size_t p = j + 1, q = n - 1; p < q;) {
                    int sum4 = sum2 + nums[p] + nums[q];
                    if (sum4 < target) {
                        p++;
                    } else if (sum4 > target) {
                        q--;
                    } else {
                        result.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;
                        while (p < q && nums[p - 1] == nums[p]) p++;
                        while (p < q && nums[q] == nums[q + 1]) q--;
                    }
                }
            }
        }
        return result;
    }
};
