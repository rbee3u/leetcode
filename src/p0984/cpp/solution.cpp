#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        char a = 'a', b = 'b';
        if (A < B) {
            swap(A, B);
            swap(a, b);
        }
        string result;
        if (A > 2 * B + 2) {
            return result;
        }
        while (A > B && B > 0) {
            result.push_back(a);
            result.push_back(a);
            A -= 2;
            result.push_back(b);
            B -= 1;
        }
        while (A > 0) {
            result.push_back(a);
            A -= 1;
            if (B > 0) {
                result.push_back(b);
                B -= 1;
            }
        }
        return result;
    }
};
