#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        vector<char> v(s.size());
        size_t i = 0;
        for (char c : s) {
            if (i >= 2 && v[i - 2] == 'a' && v[i - 1] == 'b' && c == 'c') {
                i -= 2;
            } else {
                v[i++] = c;
            }
        }
        return i == 0;
    }
};
