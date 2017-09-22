class Solution {
public:
    int maxArea(const vector<int> &hs) {
        size_t result = 0, i = 0, j = hs.size();
        while (i + 1 < j) {
            if (hs[i] < hs[j - 1]) {
                result = max(result, (j - 1 - i) * hs[i]);
                i++;
            } else {
                result = max(result, (j - 1 - i) * hs[j - 1]);
                j--;
            }
        }
        return result;
    }
};
