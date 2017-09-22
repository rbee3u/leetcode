#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        bool result = false;
        for (size_t i = 0; i < bits.size();) {
            if (bits[i] == 1) {
                result = false; i += 2;
            } else {
                result = true; i += 1;
            }
        }
        return result;
    }
};
