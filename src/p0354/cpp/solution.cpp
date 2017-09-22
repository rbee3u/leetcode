class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto comp = [] (const pair<int, int> &a, const pair<int, int> &b) {
            return (a.first<b.first)||(a.first==b.first&&a.second>b.second);
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> tail(envelopes.size()); int tail_size = 0;
        for (int index=0; index < envelopes.size(); ++index) {
            int low=0, high=tail_size-1; for (; low <= high; ) {
                int mid = low + (high - low) / 2;
                (envelopes[tail[mid]].second < envelopes[index].second)
                ? (low = mid + 1) : (high = mid - 1);
            }
            tail[low] = index; (tail_size <= low) && (tail_size = low + 1);
        }
        return tail_size;
    }
};
