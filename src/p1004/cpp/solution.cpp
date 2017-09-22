#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int result = 0;
        for (int i = -1, j = 0; j < A.size(); j++) {
            if (A[j] == 0) {
                K--;
            }
            while (K == -1) {
                i++;
                if (A[i] == 0) {
                    K++;
                }
            }
            result = max(result, j - i);
        }
        return result;
    }
};
