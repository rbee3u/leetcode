class Solution {
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        vector<int> acc(arr.size() + 1, 0);
        for (size_t i = 0; i < arr.size(); i++) {
            acc[i + 1] = acc[i] ^ arr[i];
        }
        vector<int> result(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            result[i] = acc[queries[i][1] + 1] ^ acc[queries[i][0]];
        }
        return result;
    }
};
