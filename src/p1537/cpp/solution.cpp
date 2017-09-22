class Solution {
public:
    int maxSum(vector<int> &A, vector<int> &B) {
        int64_t result = 0, a = 0, b = 0;
        for (auto i = A.begin(), j = B.begin();;) {
            if (i != A.end() && (j == B.end() || *i < *j)) {
                a += *i++; continue;
            }
            if (j != B.end() && (i == A.end() || *j < *i)) {
                b += *j++; continue;
            }
            result = (result + max(a, b)) % 1000000007;
            if (i == A.end() && j == B.end()) break;
            a = b = *i++ = *j++;
        }
        return result;
    }
};
