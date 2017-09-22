#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int x = 0, n = 0;
        for (auto i : nums) {
            if (n == 0 || x == i) {
                x = i;
                n++;
            } else {
                n--;
            }
        }
        return x;
    }
};
