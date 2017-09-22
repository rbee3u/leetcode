#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        int result = 0, n = int(A.size());
        queue<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() + K <= i) q.pop();
            if ((A[i] + int(q.size())) % 2 == 0) {
                if (i + K <= n) {
                    q.push(i);
                    result++;
                } else {
                    return -1;
                }
            }
        }
        return result;
    }
};
