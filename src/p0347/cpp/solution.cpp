class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq; for (auto x : nums) {
            if (freq.count(x)) ++freq[x]; else freq[x] = 1;
        }
        auto comp = std::greater<pair<int,int>>();
        vector<pair<int,int>> kvlist;
        int cnt = 0; for (auto &x : freq) {
            pair<int,int> pii=make_pair(x.second, x.first);
            if (++cnt <= k) {
                kvlist.push_back(pii); if (cnt == k)
                    make_heap(kvlist.begin(), kvlist.end(), comp);
            } else {
                pop_heap(kvlist.begin(), kvlist.end(), comp);
                if (kvlist.back() < pii) kvlist.back() = pii;
                push_heap(kvlist.begin(), kvlist.end(), comp);
            }
        }
        vector<int> answer; for (int i=0; i < k; ++i) {
            answer.push_back(kvlist[i].second);
        }
        return answer;
    }
};
