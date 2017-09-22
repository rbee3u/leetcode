#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) {
            return true;
        }
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) {
            return false;
        }
        this->maxChoosableInteger = maxChoosableInteger;
        this->desiredTotal = desiredTotal;
        win = vector<int>(1 << maxChoosableInteger, -1);
        return dfs(0, 0);
    }

private:
    vector<int> win;
    int maxChoosableInteger;
    int desiredTotal;
    bool dfs(int state, int total) {
        if (win[state] != -1) {
            return win[state] == 1;
        }
        if (total >= desiredTotal) {
            win[state] = 0; return false;
        }
        win[state] = 0;
        for (int i = 0; i < maxChoosableInteger; i++) {
            int state2 = state | 1 << i, total2 = total + (i + 1);
            if (state2 != state) {
                win[state] = !dfs(state2, total2);
                if (win[state] == 1) break;
            }
        }
        return win[state] == 1;
    }
};
