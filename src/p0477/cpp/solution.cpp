#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
//    int totalHammingDistance(vector<int> &nums) {
//        int result = 0, ones, n = int(nums.size());
//        for (int i = 0; i < 32; i++) {
//            ones = 0;
//            for (auto num : nums) {
//                ones += num >> i & 1;
//            }
//            result += ones * (n - ones);
//        }
//        return result;
//    }

    int totalHammingDistance(vector<int> &nums) {
        int result = 0, b[14] = {0};
        for (int num : nums) {
            for (int i = 0; num != 0; i++) {
                int tmp = b[i] & num;
                b[i] ^= num;
                num = tmp;
            }
        }
        for (int i = 0; i < 32; i++) {
            int ones = 0;
            for (int j = 0; j < 14; j++) {
                ones |= (b[j] >> i & 1) << j;
            }
            result += ones * (nums.size() - ones);
        }
        return result;
    }

};
