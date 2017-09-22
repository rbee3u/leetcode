class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int imin1 = INT_MAX, imin2 = INT_MAX;
        for (auto x : nums) {
            if (x < imin1) { imin1 = x; }
            if (imin1 < x && x < imin2) { imin2 = x; }
            if (imin2 < x) { return true; }
        }
        return false;
    }
};
