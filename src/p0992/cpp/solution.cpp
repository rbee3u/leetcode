#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &A, int K) {
        return int(atMost(A, K)) - int(atMost(A, K - 1));
    }

private:
    size_t atMost(vector<int> &A, size_t K) {
        if (K == 0) {
            return 0;
        }
        size_t result = 0;
        unordered_map<int, size_t> count;
        for (size_t i = 0, j = 0; j < A.size(); j++) {
            count[A[j]]++;
            if (j + 1 == A.size() || (count.size() == K && count.find(A[j + 1]) == count.end())) {
                while ((j + 1 == A.size() || count.size() == K) && i <= j) {
                    result += j - i + 1;
                    count[A[i]]--;
                    if (count[A[i]] == 0) {
                        count.erase(A[i]);
                    }
                    i++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> A = {1, 2};
    sol.subarraysWithKDistinct(A, 1);
}