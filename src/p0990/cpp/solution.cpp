#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UFSet {
public:
    UFSet() {
        for (int i = 0; i < MAXN; i++) {
            father[i] = i;
        }
    }
    void merge(int i, int j) {
        father[find(j)] = find(i);
    }
    int find(int i) {
        int root = i;
        while (root != father[root]) {
            root = father[root];
        }
        while (father[i] != root) {
            int j = father[i];
            father[i] = root;
            i = j;
        }
        return root;
    }

private:
    static const int MAXN = 26;
    int father[MAXN];
};

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        UFSet ufs;
        for (auto &equation : equations) {
            if (equation[1] == '=') {
                ufs.merge(equation[0] - 'a', equation[3] - 'a');
            }
        }
        for (auto &equation : equations) {
            if (equation[1] == '!') {
                auto ri = ufs.find(equation[0] - 'a');
                auto rj = ufs.find(equation[3] - 'a');
                if (ri == rj) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<string> equations = {"b!=f","c!=e","f==f","d==f","b==f","a==f"};
    sol.equationsPossible(equations);
}