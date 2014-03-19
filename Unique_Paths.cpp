class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        vector<vector<int>> nPaths(m, vector<int>(n,1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                nPaths[i][j] = nPaths[i - 1][j] + nPaths[i][j - 1];
            }
        }
        return nPaths[m - 1][n - 1];
    }
};