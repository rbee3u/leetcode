class Solution {
public:
    int numJewelsInStones(const string &J, const string &S) {
        int result = 0;
        vector<int> dict(256, 0);
        for (auto k : J) {
            dict[k] = 1;
        }
        for (auto k : S) {
            result += dict[k];
        }
        return result;
    }
};
