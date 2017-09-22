class Solution {
public:
    int closestToTarget(vector<int> &arr, int target) {
        preProcess(arr);
        int ans = INT_MAX;
        for (unsigned i = 0, j = 0; i < n && j <= n;) {
            int delta = getInterval(i, j) - target;
            (delta < 0) ? (i++) : (j++);
            ans = min(ans, abs(delta));
        }
        return int(ans);
    }

private:
    unsigned n, l;
    static const unsigned N = 100001, L = 21;
    static unsigned prefix[N][L];

    void preProcess(vector<int> &arr) {
        n = arr.size();
        int val = *max_element(arr.begin(), arr.end());
        l = unsigned(ceil(log2(val + 1)));
        for (int i = 0; i < n; i++) {
            for (unsigned k = 0; k < l; k++) {
                unsigned b = (unsigned(arr[i]) >> k) & 1U;
                prefix[i + 1][k] = prefix[i][k] + b;
            }
        }
    }

    int getInterval(unsigned i, unsigned j) const {
        if (i == j) { return INT_MAX; }
        unsigned sum = 0;
        for (unsigned k = 0; k < l; k++) {
            unsigned b = prefix[j][k] - prefix[i][k];
            if (b == j - i) { sum |= (1U << k); }
        }
        return int(sum);
    }
};

unsigned Solution::prefix[Solution::N][Solution::L];
