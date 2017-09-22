#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool validUtf8(vector<int> &data) {
        for (auto i = 0; i < data.size(); ) {
            if ((data[i] >> 3) == 0b11110) {
                if (i + 3 < data.size()
                    && (data[i + 1] >> 6) == 0b10
                    && (data[i + 2] >> 6) == 0b10
                    && (data[i + 3] >> 6) == 0b10) {
                    i += 4; continue;
                } else {
                    return false;
                }
            }
            if ((data[i] >> 4) == 0b1110) {
                if (i + 2 < data.size()
                    && (data[i + 1] >> 6) == 0b10
                    && (data[i + 2] >> 6) == 0b10) {
                    i += 3; continue;
                } else {
                    return false;
                }
            }
            if ((data[i] >> 5) == 0b110) {
                if (i + 1 < data.size()
                    && (data[i + 1] >> 6) == 0b10) {
                    i += 2; continue;
                } else {
                    return false;
                }
            }
            if ((data[i] >> 7) == 0b0) {
                i += 1; continue;
            }
            return false;
        }
        return true;
    }
};