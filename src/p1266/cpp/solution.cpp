class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int result = 0;
        for (size_t i = 1; i < points.size(); i++) {
            auto dx = points[i][0] - points[i - 1][0];
            auto dy = points[i][1] - points[i - 1][1];
            result += max(abs(dx), abs(dy));
        }
        return result;
    }
};
