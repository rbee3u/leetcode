class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret; int n = s.length(); if (!n) return ret;
        if (words.empty()) return ret; int m = words[0].length();
        unordered_map<string,int> dict; for (auto &x : words) {
            if (dict.count(x)) {++dict[x];} else {dict[x]=1;}
        }
        unordered_map<string,int> temp; for (int i=0; i<m; ++i) {
            temp.clear(); int t=i-m; for (int j=i; j+m<=n; j+=m) {
                string b = s.substr(j, m); if (!dict.count(b)) {
                    t = j; temp.clear(); continue;
                }
                if (temp.count(b)) {++temp[b];} else {temp[b]=1;}
                while (temp[b] > dict[b]) {
                    t += m; string d = s.substr(t, m); --temp[d];
                }
                if ((j-t)/m == words.size()) {ret.push_back(t+m);}
            }
        }
        sort(ret.begin(), ret.end()); return ret;
    }
};
