class NumMatrix {
private:
    vector<vector<int>> summtr;
    int maxRow, maxCol;
    int safeSum(int row, int col) {
        if (row < 0 || maxRow <= row) {
            return 0;
        }
        if (col < 0 || maxCol <= col) {
            return 0;
        }
        return summtr[row][col];
    }
public:
    NumMatrix(vector<vector<int>> &matrix) {
        summtr = matrix;
        maxRow = matrix.size();
        maxCol = maxRow ? matrix[0].size() : 0;
        for (int row=0; row < maxRow; ++row) {
            for (int col=0; col < maxCol; ++col) {
                summtr[row][col] = 
                    safeSum(row-1, col) + safeSum(row, col-1)
                    + matrix[row][col] - safeSum(row-1, col-1);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return safeSum(row2, col2) + safeSum(row1-1, col1-1)
            - safeSum(row2, col1-1) - safeSum(row1-1, col2);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

