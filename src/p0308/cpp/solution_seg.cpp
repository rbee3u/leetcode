#include <iostream>
#include <vector>

using namespace std;


class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &data) : rows(data.size()), cols(data[0].size())
    , data(rows, vector<int>(cols, 0)), tree(rows * 4, vector<int>(cols * 4, 0)) {
        for (size_t row = 0; row < rows; row++)
            for (size_t col = 0; col < cols; col++)
                update(row, col, data[row][col]);
    }

    void update(size_t row, size_t col, int val) {
        int delta = val - data[row][col]; data[row][col] = val;
        int i, j; size_t r1, r2, rm, c1, c2, cm;
        for (i = 1, r1 = 0, r2 = rows; r1 < r2;) {
            for (j = 1, c1 = 0, c2 = cols; c1 < c2;) {
                tree[i][j] += delta;
                if (c1 + 1 == c2) break;
                cm = (c1 + c2) / 2;
                if (col < cm) { c2 = cm; j = 2 * j; }
                else { c1 = cm; j = 2 * j + 1; }
            }
            if (r1 + 1 == r2) break;
            rm = (r1 + r2) / 2;
            if (row < rm) { r2 = rm; i = 2 * i; }
            else { r1 = rm; i = 2 * i + 1; }
        }
    }

    int sumRegion(size_t row1, size_t col1, size_t row2, size_t col2) {
        return query(1, 0, rows, row1, row2 + 1, 1, 0, cols, col1, col2 + 1);
    }

    int query(int i, size_t r1, size_t r2, size_t ra, size_t rb, int j, size_t c1, size_t c2, size_t ca, size_t cb) {
        int total = 0;
        if (r1 != ra || r2 != rb) {
            size_t rm = (r1 + r2) / 2;
            if (rb <= rm) {
                total += query(2 * i + 0, r1, rm, ra, rb, j, c1, c2, ca, cb);
            } else if (rm <= ra) {
                total += query(2 * i + 1, rm, r2, ra, rb, j, c1, c2, ca, cb);
            } else {
                total += query(2 * i + 0, r1, rm, ra, rm, j, c1, c2, ca, cb);
                total += query(2 * i + 1, rm, r2, rm, rb, j, c1, c2, ca, cb);
            }
        } else if (c1 != ca || c2 != cb) {
            size_t cm = (c1 + c2) / 2;
            if (cb <= cm) {
                total += query(i, r1, r2, ra, rb, 2 * j + 0, c1, cm, ca, cb);
            } else if (cm <= ca) {
                total += query(i, r1, r2, ra, rb, 2 * j + 1, cm, c2, ca, cb);
            } else {
                total += query(i, r1, r2, ra, rb, 2 * j + 0, c1, cm, ca, cm);
                total += query(i, r1, r2, ra, rb, 2 * j + 1, cm, c2, cm, cb);
            }
        } else {
            total += tree[i][j];
        }
        return total;
    }

private:
    size_t rows, cols; vector<vector<int>> data, tree;
};
