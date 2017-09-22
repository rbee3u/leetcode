class Solution {
public:
    int minAbsoluteSumDiff(vector<int> &xs, vector<int> &ys) {
        vector<int> zs(xs);
        sort(begin(zs), end(zs));
        int sum = 0, delta = 0;
        for (size_t i = 0; i < size(xs); i++) {
            int diff = abs(xs[i] - ys[i]);
            sum = (sum + diff) % modulo;
            if (diff < delta) continue;
            auto p = lower_bound(begin(zs), end(zs), ys[i]);
            if (p != end(zs)) {
                delta = max(delta, diff - abs(*p - ys[i]));
            }
            if (p != begin(zs)) {
                delta = max(delta, diff - abs(*prev(p) - ys[i]));
            }
        }
        return (sum + modulo - delta) % modulo;
    }

private:
    static const int modulo = 1000000007;
};
