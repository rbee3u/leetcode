#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int> &A) {
        preProcess(A);
        dfs(A, 0, 0);
        return result;
    }

    void dfs(vector<int> &A, int depth, int curr) {
        if (depth == A.size()) {
            result++; return;
        }
        int same = -1;
        for (int i = 0; i < A.size(); i++) {
            if (depth > 0 && !isSquare[curr][i]) {
                continue;
            }
            if (A[i] != same && !isVisited[i]) {
                isVisited[i] = 1;
                dfs(A, depth + 1, i);
                isVisited[i] = 0;
                same = A[i];
            }
        }
    }


private:
    static const int MAXN = 14;
    int isSquare[MAXN][MAXN];
    int isVisited[MAXN];
    int result;

    void preProcess(vector<int> &A) {
        sort(A.begin(), A.end());
        memset(isSquare, 0x00, MAXN * MAXN * sizeof(int));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                int y = A[i] + A[j];
                int x = int(sqrt(double(y)));
                if (x * x == y) {
                    isSquare[i][j] = 1;
                    isSquare[j][i] = 1;
                }
            }
        }
        memset(isVisited, 0x00, MAXN * sizeof(int));
        result = 0;
    }
};

int main() {
    vector<int> v({2, 2, 2});
    Solution sol;
    cout << sol.numSquarefulPerms(v) << endl;
}