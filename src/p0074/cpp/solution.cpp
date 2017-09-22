#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        auto n = matrix.size();
        if (n == 0) return false;
        auto m = matrix[0].size();
        size_t begin = 0, end = n * m;
        while (begin < end) {
            auto mid = begin + (end - begin) / 2;
            if (matrix[mid / m][mid % m] < target) begin = mid + 1;
            else end = mid;
        }
        return (end < n * m) && (matrix[end / m][end % m] == target);
    }
};
