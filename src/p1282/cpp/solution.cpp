class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        vector<vector<int>> result;
        auto n = int(groupSizes.size());
        unordered_map<int, vector<int>> dict;
        for (auto i = 0; i < n; i++) {
            auto gs = groupSizes[i];
            dict[gs].push_back(i);
            if (dict[gs].size() == gs) {
                result.push_back(dict[gs]);
                dict[gs].clear();
            }
        }
        return result;
    }
};
