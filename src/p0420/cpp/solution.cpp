#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;


class Solution {
public:
    int strongPasswordChecker(const string &s) const {

        int length = static_cast<int>(s.size()), missing = 3;
        missing -= any_of(s.begin(), s.end(), [](char c) { return islower(c); });
        missing -= any_of(s.begin(), s.end(), [](char c) { return isupper(c); });
        missing -= any_of(s.begin(), s.end(), [](char c) { return isdigit(c); });
        if (length < 6) {
            return max(missing, 6 - length);
        }

        int update = 0, r[3] = {0, 0, 0};
        for (int j = 0, i = 1, k; i <= length; i++) {
            if (i == length || s[i - 1] != s[i]) {
                k = i - j; j = i; if (k >= 3) {
                    update += k / 3; r[k % 3]++;
                }
            }
        }
        if (length <= 20) {
            return max(missing, update);
        }

        int remove = length - 20, rest = remove;
        r[0] = min(r[0], rest / 1); rest -= 1 * r[0]; update -= r[0];
        r[1] = min(r[1], rest / 2); rest -= 2 * r[1]; update -= r[1];
        return remove + max(missing, update - rest / 3);
    }
};

int main() {
    Solution sol;
    cout << sol.strongPasswordChecker("aaaaaa1234567890123Ubefg") << endl;
    return 0;
}