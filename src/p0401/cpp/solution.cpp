#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                int n = (h << 6) | m;
                n -= n >> 1 & 0x55555555;
                n = (n & 0x33333333) + (n >> 2 & 0x33333333);
                n = n + (n >> 4) & 0x0f0f0f0f;
                n = n + (n >> 8) & 0x00ff00ff;
                if (n == num) {
                    char buff[6];
                    sprintf(buff, "%d:%02d", h, m);
                    result.emplace_back(buff);
                }
            }
        }
        return result;
    }
};
