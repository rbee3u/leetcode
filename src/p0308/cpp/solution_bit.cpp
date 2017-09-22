#include <iostream>
#include <vector>

using namespace std;


class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &data) : rows(data.size()), cols(data[0].size())
    , data(rows, vector<int>(cols, 0)), tree(rows, vector<int>(cols, 0)) {
        for (size_t row = 0; row < rows; row++)
            for (size_t col = 0; col < cols; col++)
                update(row, col, data[row][col]);
    }

    void update(size_t row, size_t col, int val) {
        incr(row + 1, col + 1, val - data[row][col]);
        data[row][col] = val;
    }
    void incr(size_t row, size_t col, int delta) {
        for (size_t i = row; i <= rows; i += i & (-i))
            for (size_t j = col; j <= cols; j += j & (-j))
                tree[i - 1][j - 1] += delta;
    }

    int sumRegion(size_t row1, size_t col1, size_t row2, size_t col2) {
        return query(row2 + 1, col2 + 1) + query(row1, col1)
             - query(row1, col2 + 1) - query(row2 + 1, col1);
    }
    int query(size_t row, size_t col) {
        int total = 0;
        for (auto i = row; i > 0; i -= i & (-i))
            for (auto j = col; j > 0; j -= j & (-j))
                total += tree[i - 1][j - 1];
        return total;
    }

private:
    size_t rows, cols; vector<vector<int>> data, tree;
};

int main() {
    vector<vector<int>> data = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix sol(data);
    cout << sol.sumRegion(2, 1, 4, 3) << endl;
    sol.update(3, 2, 2);
    cout << sol.sumRegion(2, 1, 4, 3) << endl;
    return 0;
}
