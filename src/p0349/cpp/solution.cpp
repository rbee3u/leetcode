class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        unordered_set<int> sets1(nums1.begin(), nums1.end());
        unordered_set<int> sets2(nums2.begin(), nums2.end());
        for (auto &x : sets1) if (sets2.count(x)) {
            intersection.push_back(x);
        }
        return intersection;
    }
};
