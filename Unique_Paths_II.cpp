class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> nPaths(m, vector<int>(n, 0));
        nPaths[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < m; ++i) {
            nPaths[i][0] = (1 - obstacleGrid[i][0]) * nPaths[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            nPaths[0][j] = (1 - obstacleGrid[0][j]) * nPaths[0][j - 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                nPaths[i][j] = (1 - obstacleGrid[i][j]) * (nPaths[i - 1][j] + nPaths[i][j - 1]);
            }
        }
        return nPaths[m - 1][n - 1];
    }
};