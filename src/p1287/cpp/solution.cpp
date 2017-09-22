class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int n = int(arr.size()), count = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] != arr[i - 1]) {
                count = 0;
            }
            count++;
            if (count * 4 > n) { return arr[i]; }
        }
        return 0;
    }
};
