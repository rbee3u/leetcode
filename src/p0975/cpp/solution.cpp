#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int> &A) {
        int result = 1;
        size_t n = A.size();
        map<int, size_t> tree;
        tree[A[n - 1]] = n - 1;
        vector<int> odd(n, 0), even(n, 0);
        odd[n - 1] = even[n - 1] = 1;
        for (size_t i = n - 1; i--; tree[A[i]] = i) {
            auto greaterOrEqual = tree.lower_bound(A[i]);
            if (greaterOrEqual != tree.end()) {
                result += odd[i] = even[greaterOrEqual->second];
            }
            auto lessOrEqual = tree.upper_bound(A[i]);
            if (lessOrEqual != tree.begin()) {
                even[i] = odd[(--lessOrEqual)->second];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> A({{1, 2, 3, 2, 1, 4, 4, 5}});
    cout << sol.oddEvenJumps(A) << endl;
};