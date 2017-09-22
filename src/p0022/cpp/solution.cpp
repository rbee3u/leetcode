class Solution {
private:
    void dfs(vector<string> &ret, string tmp, int lft, int rht) {
        if (!lft && !rht) {ret.push_back(tmp); return;}
        if (lft > 0) {dfs(ret, tmp + '(', lft-1, rht);}
        if (lft<rht) {dfs(ret, tmp + ')', lft, rht-1);}
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret; dfs(ret, "", n, n);
        return ret;
    }
};
