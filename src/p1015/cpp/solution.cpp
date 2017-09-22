#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int numDupDigitsAtMostN(int x) {
        vector<int> ds; auto n = 0;
        for (auto y = x + 1; y > 0; y /= 10) {
            ds.push_back(y % 10); n++;
        }
        reverse(ds.begin(), ds.end());
        auto distinct = 0;
        for (auto i = 1; i < n; i++) {
            distinct += 9 * A(9, i - 1);
        }
        bool visited[10] = {false};
        for (auto i = 0; i < n; i++) {
            for (int j = !i; j < ds[i]; j++) {
                if (!visited[j]) {
                    distinct += A(9 - i, n - i - 1);
                }
            }
            if (visited[ds[i]]) break;
            visited[ds[i]] = true;
        }
        return x - distinct;
    }

private:
    int A(int n, int m) {
        int r = 1; while (m--) r *= n--; return r;
    }
};

int main() {
    Solution sol;
    cout << sol.numDupDigitsAtMostN(110) << endl;
    return 0;
}