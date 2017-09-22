class Solution {
public:
    string defangIPaddr(const string &address) {
        string result;
        for (auto x : address) {
            if (x == '.') {
                result.append("[.]");
            } else {
                result.push_back(x);
            }
        }
        return result;
    }
};
