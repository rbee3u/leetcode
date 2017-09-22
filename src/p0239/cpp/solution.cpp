class Solution {
public:
    class MyQue {
    public:
        deque< pair<int, int> > q;
        int k;
        MyQue(int ak): k(ak) {}
        ~MyQue() {}
        void push(int index, int value) {
            while (!q.empty()
                && (q.front().first+k <= index)) {
                q.pop_front();
            }
            while (!q.empty()
                && (q.back().second <= value)) {
                q.pop_back();
            }
            q.push_back(make_pair(index, value));
        }
        int query() {
            return q.front().second;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        MyQue mq(k);
        int len = nums.size();
        if (len <= 0 || len < k) {
            return ret;
        }
        for (int i = 0; i < k-1; ++i) {
            mq.push(i, nums[i]);
        }
        for (int i = k-1; i < len; ++i) {
            mq.push(i, nums[i]);
            ret.push_back(mq.query());
        }
        return ret;
    }
};
