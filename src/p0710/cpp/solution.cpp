#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        total = N;
        for (int r : blacklist) {
            total += jump[r] = -1;
        }
        for (int r : blacklist) {
            if (r >= total) continue;
            while (jump.count(N - 1)) {
                N--;
            }
            jump[r] = --N;
        }
        mt = mt19937(rd());
    }

    int pick() {
        int x = dist(mt) % total;
        if (jump.count(x)) {
            x = jump[x];
        }
        return x;
    }

private:
    unordered_map<int, int> jump;
    int total;
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */