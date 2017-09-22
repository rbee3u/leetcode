#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int k) {
        auto n = flowerbed.size();
        for (int i = 0; i < n;) {
            if (flowerbed[i] == 0 && (i - 1 < 0 || flowerbed[i - 1] == 0) && (i + 1 >= n || flowerbed[i + 1] == 0 )) {
                k--; i += 2;
            } else {
                i++;
            }
        }
        return k <= 0;
    }
};
