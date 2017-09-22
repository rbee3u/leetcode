class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnts1;
        for (auto &x : nums1) { ++cnts1[x]; }
        vector<int> intersection;
        for (auto &x : nums2) if (--cnts1[x] >= 0) {
            intersection.push_back(x);
        }
        return intersection;
    }
};
