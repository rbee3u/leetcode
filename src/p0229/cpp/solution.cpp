class Solution {
private:
    bool isMajority(vector<int>& nums, int elem) {
        int count=0; for (auto e : nums) {
            if (e == elem) ++count;
        }
        return count*3 > nums.size();
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x, xcnt=0, y, ycnt=0;
        for (auto z : nums) {
            if (!xcnt || x==z) {
                x = z; ++xcnt;
            } else
            if (!ycnt || y==z) {
                y = z; ++ycnt;
            } else {
                --xcnt; --ycnt;
                if (!xcnt && ycnt) {
                    xcnt = ycnt;
                    x = y; ycnt = 0;
                }
            }
        }
        vector<int> ret;
        if (xcnt && isMajority(nums, x)) {
            ret.push_back(x);
        }
        if (ycnt && isMajority(nums, y)) {
            ret.push_back(y);
        }
        return ret;
    }
};
