class Solution {
private:
    int compare(string s) {
        int lft=0, rht=0; for (auto x : s) {
            (x == '(') && (++lft);
            (x == ')') && (++rht);
            if (lft < rht) break;
        }
        return (lft - rht);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q; q.push(s);
        unordered_set<string> h; h.insert(s);
        for (int mlen=-1; !q.empty(); ) {
            string e = q.front(); q.pop();
            int elength = e.length();
            if (elength < mlen) break;
            int cmp = compare(e);
            if (cmp == 0) {
                if (mlen == -1) {
                    h.clear();
                    mlen = elength;
                }
                h.insert(e);
                continue;
            }
            if (mlen == -1) {
                for (int i=0; i < elength; ++i) {
                    if (cmp < 0 && e[i]==')'
                     || cmp > 0 && e[i]=='(') {
                        string f = e; f.erase(i, 1);
                        if (h.find(f) == h.end()) {
                            q.push(f); h.insert(f);
                        }
                    }
                }
            }
        }
        vector<string> ret;
        for (auto x : h) {
            ret.push_back(x);
        }
        return ret;
    }
};
