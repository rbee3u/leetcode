class Solution {
public:
    bool wordPattern(string pat, string str) {
        int pl=pat.length();
        vector<string> vec;
        string tmp; for (auto x : str+' ') {
            if (x == ' ') {
                vec.push_back(tmp);
                tmp = "";
            } else {
                tmp += x;
            }
        }
        int vl=vec.size();
        if (pl != vl) {
            return false;
        }
        unordered_map<char, string> dict;
        unordered_set<string> sets;
        for (int i=0; i < pl; ++i) {
            auto it = dict.find(pat[i]);
            if (it == dict.end()) {
            	if (sets.find(vec[i]) == sets.end()) {
            		dict[pat[i]] = vec[i];
            		sets.insert(vec[i]);
            	} else {
            		return false;
            	}
            } else {
            	if (it->second != vec[i]) {
            		return false;
            	}
            }
        }
        return true;
    }
};
