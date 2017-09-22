class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        assert(numRows >= 0);
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; ++i) {
            vector<int> tmp(i+1, 1);
            for (int j=1; j < i; ++j) {
                tmp[j] = ret[i-1][j-1]
                        + ret[i-1][j];
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
