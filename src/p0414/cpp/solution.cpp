#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int first = 0, second = 0, third = 0, counter = 0;
        for (auto num : nums) {
            if (counter == 0) {
                first = num; counter++;
            } else if (counter == 1) {
                if (num > first) {
                    second = first; first = num; counter++;
                } else if (num < first) {
                    second = num; counter++;
                }
            } else if (counter == 2) {
                if (num > first) {
                    third = second; second = first; first = num; counter++;
                } else if (num > second && num < first) {
                    third = second; second = num; counter++;
                } else if (num < second) {
                    third = num; counter++;
                }
            } else {
                if (num > first) {
                    third = second; second = first; first = num;
                } else if (num > second && num < first) {
                    third = second; second = num;
                } else if (num > third && num < second) {
                    third = num;
                }
            }
        }
        return (counter >= 3) ? third : first;
    }
};