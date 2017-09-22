class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals) {
        auto cmp = [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 1, right = intervals[0][1];
        for (int j = 1; j < intervals.size(); j++) {
            if (intervals[j][1] > right) {
                result++;
                right = intervals[j][1];
            }
        }
        return result;
    }
};
