class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if (n1 == 0) {
            return n2;
        }
        if (n2 == 0) {
            return n1;
        }
        vector<vector<int>> table(2, vector<int>(n1 + 1));
        for (int i = 0; i <= n1; ++i) {
            table[1][i] = i;
        }
        for (int i = 1; i <= n2; ++i) {
            char cur = word2[i - 1];
            table[0] = table[1];
            table[1][0] = table[0][0] + 1;
            for (int j = 1; j <= n1; ++j) {
                int replaceCost = 1;
                if (word1[j - 1] == cur) {
                    replaceCost = 0;
                }
                table[1][j] = min(min (table[1][j - 1], table[0][j]) + 1, table[0][j - 1] + replaceCost);
            }
        }
        return table[1][n1];
    }
};