#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int x2 = 0, x1 = 0, mask;
        for (auto i : nums){
            x2 ^= (x1 & i);
            x1 ^= i;
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    }
};
