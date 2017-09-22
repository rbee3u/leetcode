#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool pyramidTransition(string &bottom, vector<string> &allowed) {
        dict.clear();
        for (auto &s : allowed) {
            int key = ord(s[1]) << 3 | ord(s[0]);
            dict[key].insert(ord(s[2]));
        }
        black.clear();
        found = false;

        int init_state = 0;
        for (auto c : bottom) {
            init_state = (init_state << 3) | ord(c);
        }
        init_state = rev(init_state);

        dfs(init_state);

        return found;
    }

private:
    unordered_map<int, unordered_set<int>> dict;
    unordered_set<int> black;
    bool found;

    void dfs(int curr_state) {
        if (found || black.count(curr_state)) return;
        int key = curr_state & 0b111111;
        if (key == (curr_state & 0b111)) {
            found = true; return;
        }
        unordered_set<int> next_states;
        nss(curr_state, 0, next_states);
        for (auto next_state : next_states) {
            dfs(next_state);
        }
        if (!found) {
            black.insert(curr_state);
        }
    }

    int ord(char c) {
        return c - 'A' + 1;
    }
    int rev(int s) {
        int r;
        for (r = 0; s != 0; s >>= 3) {
            r = (r << 3) | (s & 7);
        }
        return r;
    }
    void nss(int curr_state, int next_state, unordered_set<int> &next_states) {
        int key = curr_state & 0b111111;
        if (key == (curr_state & 0b111)) {
            next_states.insert(rev(next_state)); return;
        }
        curr_state >>= 3;
        for (int val : dict[key]) {
            nss(curr_state, next_state << 3 | val, next_states);
        }
    }
};

int main() {
    Solution sol;
    string bottom = "AABA";
    vector<string> allowed = {"AAA","AAB","ABA","ABB","BAC"};
    cout << sol.pyramidTransition(bottom, allowed) << endl;
    return 0;
}