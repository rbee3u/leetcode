class Solution {
public:
    static int jump(const std::vector<int> &nums) {
        int result = 0, start = 0, reach = 1;
        for (int i = 0; reach < nums.size(); i++) {
            if (i >= start) { result++; start = reach; }
            reach = std::max(reach, i + nums[i] + 1);
        }
        return result;
    }
};
