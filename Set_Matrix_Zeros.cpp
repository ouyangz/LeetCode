class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int nRows = matrix.size();
        if (nRows == 0) {
            return;
        }
        int nCols = (matrix[0]).size();
        if (nCols == 0) {
            return;
        }
        vector<bool> zeroRows(nRows, false);
        vector<bool> zeroCols(nCols, false);
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                if (zeroRows[i] || zeroCols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};