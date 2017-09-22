class Solution {
public:
    vector<int> replaceElements(vector<int> &arr) {
        auto n = int(arr.size());
        vector<int> result(n, 0);
        int maximum = -1;
        for (auto i = n - 1; i >= 0; i--) {
            result[i] = maximum;
            maximum = max(maximum, arr[i]);
        }
        return result;
    }
};
