#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<PII> pairs; size_t n = 0;
        for (int num : nums) {
            pairs.emplace_back(n++, num);
        }
        vector<int> result(n, 0);
        mergeSort(pairs, 0, n, result);
        return result;
    }

private:
    typedef pair<size_t, int> PII;
    void mergeSort(vector<PII> &pairs, size_t p, size_t q, vector<int> &result) {
        if (p + 1 >= q) return;
        size_t m = (p + q) / 2, i = 0, j = 0, k = p;
        mergeSort(pairs, p, m, result); vector<PII> lhs(&pairs[p], &pairs[m]);
        mergeSort(pairs, m, q, result); vector<PII> rhs(&pairs[m], &pairs[q]);
        while (p + i < m || m + j < q) {
            if (p + i < m && (m + j == q || lhs[i].second <= rhs[j].second)) {
                result[lhs[i].first] += j; pairs[k++] = lhs[i++];
            } else {
                pairs[k++] = rhs[j++];
            }
        }
    }
};
