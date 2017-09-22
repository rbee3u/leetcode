class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        auto n = int(arr.size());
        vector<bool> seen(n, false);
        queue<int> q;
        seen[start] = true;
        q.push(start);
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            if (arr[i] == 0) {
                return true;
            }
            auto left = i - arr[i];
            if (left >= 0 && !seen[left]) {
                seen[left] = true;
                q.push(left);
            }
            auto right = i + arr[i];
            if (right < n && !seen[right]) {
                seen[right] = true;
                q.push(right);
            }
        }
        return false;
    }
};
