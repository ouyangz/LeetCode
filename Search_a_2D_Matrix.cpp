class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int nRows = matrix.size();
        if (nRows == 0) {
            return false;
        }
        int nCols = matrix[0].size();
        if (nCols == 0) {
            return false;
        }
        int i = 0;
        int j = nCols - 1;
        bool found = false;
        while (i < nRows && j >= 0) {
            if (target == matrix[i][j]) {
                found = true;
                break;
            }
            else if (target < matrix[i][j]) {
                --j;
            }
            else {
                ++i;
            }
        }
        return found;
    }
};