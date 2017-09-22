class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        if (n % 2 != 0) {
            result.push_back(0);
            n--;
        }
        while (n > 0) {
            result.push_back(n);
            result.push_back(-n);
            n -= 2;
        }
        return result;
    }
};
