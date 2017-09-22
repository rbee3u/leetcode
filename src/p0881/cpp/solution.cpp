#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int> &weights, int limit) {
        sort(weights.begin(), weights.end());
        vector<int>::size_type i = 0, j = weights.size() - 1;
        int result = 0;
        for (; i < j; j--) {
            result++;
            if (weights[i] + weights[j] <= limit) {
                i++;
            }
        }
        result += (i == j);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> people = {1, 2};
    cout << sol.numRescueBoats(people, 3) << endl;
    return 0;
}