class Solution {
private:
    string num2str(int num) {
        char buff[11];
        sprintf(buff, "%d", num);
        return buff;
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0, j = 0, n = nums.size();
        for (; ; ) {
            if (i >= n) break;
            for (; j+1 < n && nums[j]+1 == nums[j+1]; ) {
                ++j;
            }
            string tmp(num2str(nums[i]));
            if (i < j) {
                tmp += "->" + num2str(nums[j]);
            }
            ret.push_back(tmp);
            i = j + 1; j = j + 1;
        }
        return ret;
    }
};
