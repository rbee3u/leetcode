class Solution {
public:
    int trap(vector<int> &height) {
        int water = 0, lbound = 0, rbound = 0;
        auto left = height.begin(), right = height.end();
        while (left < right) {
            if (lbound < rbound) {
                int curr = *(left++);
                lbound = max(lbound, curr);
                water += lbound - curr;
            } else {
                int curr = *(--right);
                rbound = max(rbound, curr);
                water += rbound - curr;
            }
        }
        return water;
    }
};
