#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        int result = 0;
        for (int j = -1, i = 0; i < seats.size(); i++) {
            if (seats[i] == 0) {
                if (j + 1 == 0 || i + 1 == seats.size()) {
                    result = max(result, i - j);
                } else {
                    result = max(result, (i - j + 1) / 2);
                }
            } else {
                j = i;
            }
        }
        return result;
    }
};