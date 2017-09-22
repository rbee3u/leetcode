#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findMin(vector<int> &array) {
        size_t l = 0, r = array.size();
        for (int back = array[--r]; l < r;) {
            size_t m = l + (r - l) / 2;
            if (array[m] <= back) r = m;
            else l = m + 1;
        }
        return array[l];
    }
};
