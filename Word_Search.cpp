class Solution {
private:
    vector<vector<int>> found;
    int nRows;
    int nCols;
public:
    bool exist(vector<vector<char> > &board, string word) {
        nRows = board.size();
        if (nRows == 0) {
            return false;
        }
        nCols = board[0].size();
        if(nCols == 0) {
            return false;
        }
        if (word.size() == 0) {
            return true;
        }
        found = vector<vector<int>> (nRows, vector<int>(nCols, -1));

        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                if (existHelper(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool existHelper(vector<vector<char> > &board, int x, int y, string word, int pos) {
        if (board[x][y] != word[pos] || found[x][y] != -1) {
            return false;
        }
        if (pos == word.size() - 1) {
            return true;
        }
        found[x][y] = pos;
        if ((x + 1 < nRows && existHelper(board, x + 1, y, word, pos + 1)) ||
            (x - 1 >= 0    && existHelper(board, x - 1, y, word, pos + 1)) ||
            (y + 1 < nCols && existHelper(board, x, y + 1, word, pos + 1)) ||
            (y - 1 >= 0    && existHelper(board, x, y - 1, word, pos + 1))) {
            return true;
        }
        found[x][y] = -1;
        return false;
    }
};