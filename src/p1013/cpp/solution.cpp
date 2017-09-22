#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &times) {
        int result = 0, counts[60] = {0};
        for (auto time : times) {
            time %= 60;
            result += counts[(60 - time) % 60];
            counts[time]++;
        }
        return result;
    }
};
