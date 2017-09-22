#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> result;
        int carry = 0;
        for (auto i = A.size(); carry > 0 || K > 0 || i > 0;) {
            if (i > 0) {
                i--;
                carry += A[i];
            }
            carry += K % 10;
            result.push_back(carry % 10);
            carry /= 10;
            K /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};