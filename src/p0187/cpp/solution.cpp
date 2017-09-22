#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(const string &s) {
        vector<string> result;
        unordered_map<int, int> count;
        for (int i = 0, h = 0; i < s.size(); i++) {
            h = ((h & 0x07ffffff) << 3) | (s[i] & 7);
            if ((count[h]++) == 1) {
                result.push_back(s.substr(i - 9, 10));
            }
        }
        return result;
    }
};
