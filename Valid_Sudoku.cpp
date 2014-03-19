class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Each row
        for (int i = 0; i < 9; ++i) {
            set<char> filled;
            for (int j = 0; j < 9; ++j) {
                char cur = board[i][j];
                if (cur != '.' && filled.count(cur) != 0) {
                    return false;
                }
                filled.insert(cur);
            }
        }
        // Each column
        for (int i = 0; i < 9; ++i) {
            set<char> filled;
            for (int j = 0; j < 9; ++j) {
                char cur = board[j][i];
                if (cur != '.' && filled.count(cur) != 0) {
                    return false;
                }
                filled.insert(cur);
            }
        }
        // Each block
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                set<char> filled;
                for (int l = 0; l < 3; ++l) {
                    for (int m = 0; m < 3; ++m) {
                        char cur = board[i + l][j + m];
                        if (cur != '.' && filled.count(cur) != 0) {
                            return false;
                        }
                        filled.insert(cur);
                    }
                }
            }
        }
        // Passed all
        return true;
    }
};