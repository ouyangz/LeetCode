class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<string> blank(n, string(n,'.'));
        vector<int> y;
        int pos = 0;
        while (true) {
            if (y.size() == n) {
                vector<string> cur = blank;
                for (int i = 0; i < n; ++i) {
                    cur[i][y[i]] = 'Q';
                }
                result ++;
                if (findNext(y, pos, n) == -1){
                    break;
                }
            }
            if (isValid(y, pos, n)) {
                y.push_back(pos);
                pos = 0;
                continue;
            }
            else if (pos != n - 1){
                ++pos;
            }
            else if (findNext(y, pos, n) == -1){
                break;
            }
        }
        return result;
    }
    
private:
    bool isValid(vector<int> &y, int pos, int n) {
        int row = y.size();
        if (row == 0) {
            return true;
        }
        for (int i = 0; i < row; ++i) {
            if (pos == y[i] || pos == y[i] + row - i || pos == y[i] - row + i) {
                return false;
            }
        }
        return true;
    }
    
    int findNext(vector<int> &y, int &pos, int n) {
        while (y.size() > 0 && y.back() == n - 1) {
            y.pop_back();
        }
        if (y.size() == 0) {
            return -1;
        }
        pos = y.back() + 1;
        y.pop_back();
        return 0;
    }
};