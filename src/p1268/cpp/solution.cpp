class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string &searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string prefix;
        for (auto c : searchWord) {
            prefix.push_back(c);
            result.emplace_back();
            auto it = lower_bound(products.begin(), products.end(), prefix);
            while (it != products.end() && result.back().size() < 3) {
                if (it->substr(0, prefix.size()) != prefix) break;
                result.back().push_back(*it++);
            }
        }
        return result;
    }
};
