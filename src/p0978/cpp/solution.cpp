#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(const vector<int> &xs) const {
        int maxSize = 1, currSize = 1, state = 0;
        for (auto i = 1; i < xs.size(); i++) {
            if (state < 0) {
                if (xs[i - 1] < xs[i]) {
                    state = 1;
                    currSize++;
                    if (maxSize < currSize) {
                        maxSize = currSize;
                    }
                } else if (xs[i - 1] > xs[i]) {
                    state = -1;
                    currSize = 2;
                } else {
                    state = 0;
                    currSize = 1;
                }
            } else if (state > 0) {
                if (xs[i - 1] > xs[i]) {
                    state = -1;
                    currSize++;
                    if (maxSize < currSize) {
                        maxSize = currSize;
                    }
                } else if (xs[i - 1] < xs[i]) {
                    state = 1;
                    currSize = 2;
                } else {
                    state = 0;
                    currSize = 1;
                }
            } else {
                if (xs[i - 1] < xs[i]) {
                    state = 1;
                    currSize++;
                    if (maxSize < currSize) {
                        maxSize = currSize;
                    }
                } else if (xs[i - 1] > xs[i]) {
                    state = -1;
                    currSize++;
                    if (maxSize < currSize) {
                        maxSize = currSize;
                    }
                } else {
                }
            }
        }
        return maxSize;
    }
};