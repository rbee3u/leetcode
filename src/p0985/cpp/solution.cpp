#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
        vector<int> result;
        int sum = 0; for (auto a : A) if (a % 2 == 0) sum += a;
        for (auto &query : queries) {
            if (A[query[1]] % 2 == 0 && query[0] % 2 == 0) {
                sum += query[0];
            } else if (A[query[1]] % 2 == 0 && query[0] % 2 != 0) {
                sum -= A[query[1]];
            } else if (A[query[1]] % 2 != 0 && query[0] % 2 != 0) {
                sum += A[query[1]] + query[0];
            }
            A[query[1]] += query[0];
            result.push_back(sum);
        }
        return result;
    }
};