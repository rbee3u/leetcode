#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(const vector<int> &xs) const {
        size_t n = xs.size(), i = 0, j = n - 1, k = n - 1;
        vector<int> ys(n);
        while (i <= j) {
            if (abs(xs[i]) >= abs(xs[j])) {
                ys[k--] = xs[i] * xs[i];
                i++;
            } else {
                ys[k--] = xs[j] * xs[j];
                j--;
            }
        }
        return ys;
    }
};
