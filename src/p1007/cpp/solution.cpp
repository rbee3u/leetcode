#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minDominoRotations(const vector<int> &A, const vector<int> &B) {
        auto n = A.size();
        int i, a, b;
        for (auto choose : {A[0], B[0]}) {
            for (i = a = b = 0; i < n && (A[i] == choose || B[i] == choose); i++) {
                a += (A[i] != choose); b += (B[i] != choose);
                if (i + 1 == n) return min(a, b);
            }
        }
        return -1;
    }
};
