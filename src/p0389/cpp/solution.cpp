#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    char findTheDifference(string s, string t) {
        char r = 0;
        for (auto c : s) r ^= c;
        for (auto c : t) r ^= c;
        return r;
    }
};
