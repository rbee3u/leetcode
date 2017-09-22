class Solution {
public:
    int findBestValue(vector<int> &arr, int target) {
        arr.push_back(0);
        sort(arr.begin(), arr.end());
        int n = int(arr.size()), i;
        vector<int> sum(n, 0);
        for (i = 1; i < n; i++) {
            if (sum[i - 1] + (n - i) * arr[i] >= target) {
                break;
            }
            sum[i] = sum[i - 1] + arr[i];
        }
        if (i == n) {
            return arr[n - 1];
        }
        int lo = sum[i - 1] + (n - i) * arr[i - 1] - target;
        int hi = sum[i - 1] + (n - i) * arr[i] - target;
        if (abs(lo % (n - i)) <= abs(hi % (n - i))) {
            return arr[i - 1] - lo / (n - i);
        } else {
            return arr[i] - hi / (n - i);
        }
    }
};
