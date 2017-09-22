class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret; vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(ret, tmp, candidates, target, 0);
        return ret;
    }
private:
    void dfs(vector<vector<int>> &ret, vector<int> &tmp, vector<int> &candidates, int remain, int start) {
        if (0 == remain) {ret.push_back(tmp); return;}
        for (int i = start; i < candidates.size() && remain >= candidates[i]; ++i) {
            tmp.push_back(candidates[i]);
            dfs(ret, tmp, candidates, remain-candidates[i], i);
            tmp.pop_back();
        }
    }
};
