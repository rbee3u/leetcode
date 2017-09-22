#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& A) {
        vector<int> dp(MAXM, -1);
        int result = 0;
        for (auto i : A) {
            for (auto j : A) {
                auto t = i & j;
                if (dp[t] == -1) {
                    dp[t] = 0;
                    for (auto k : A) {
                        if ((t & k) == 0) {
                            dp[t] += 1;
                        }
                    }
                }
                result += dp[t];
            }
        }
        return result;
    }

private:
    static constexpr int MAXM = 65536;
};
