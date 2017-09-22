#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class Solution {
public:
    Solution(vector<int> w) : sum(w) {
        total = sum[0];
        for (auto i = 1; i < sum.size(); i++) {
            total += sum[i];
            sum[i] += sum[i - 1];
        }
        mt = mt19937(rd());
        dist = uniform_int_distribution<>(0, total - 1);
    }

    int pickIndex() {
        return upper_bound(sum.begin(), sum.end(), dist(mt)) - sum.begin();
    }

private:
    vector<int> sum;
    int total;
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */