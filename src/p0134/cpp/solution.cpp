class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int sum = 0, minSum = INT_MAX, minIdx = -1;
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            if (minSum >= sum) {
                minSum = sum; minIdx = i;
            }
        }
        return sum >= 0 ? (minIdx + 1) % n : -1;
    }
};
