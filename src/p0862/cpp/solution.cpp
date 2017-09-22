#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <deque>

using namespace std;


class Solution {
public:
    int shortestSubarray(vector<int> &A, int K) {
        auto n = A.size(); vector<int> B(n + 1, 0);
        for (auto i = 0; i < n; i++) {
            B[i + 1] = B[i] + A[i];
        }
        deque<int> q; int result = INT_MAX;
        for (auto i = 0; i <= n; i++) {
            while (!q.empty() && B[i] - B[q.front()] >= K) {
                result = min(result, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && B[i] - B[q.back()] <= 0) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return result == INT_MAX ? -1 : result;
    }
};
