class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        vector<int> temp = matrix[0];
        for (int j = 0; j < n / 2; ++j) {
            int m = n - j;
            vector<int> temp(matrix[j].begin() + j, matrix[j].begin() + m);
            for (int i = 0; i < n - 2 * j - 1; ++i) {
                matrix[j][j + i] = matrix[m - 1 - i][j];
                matrix[m - 1 - i][j] = matrix[m - 1][m - 1 - i];
                matrix[m - 1][m - 1 - i] = matrix[j + i][m - 1];
                matrix[j + i][m - 1] = temp[i];
            }
        }
    }
};