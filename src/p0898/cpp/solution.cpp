#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int> &nums) {
        unordered_set<int> result;
        unordered_set<int> s;
        for (auto num : nums) {
            s.insert(0);
            unordered_set<int> t;
            for (auto x : s) {
                t.insert(x | num);
                result.insert(x | num);
            }
            s.swap(t);
        }
        return result.size();
    }
};
