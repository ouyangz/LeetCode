class Solution {
public:
    string convert(string s, int nRows) {
        string result;
        if (nRows < 1) {
            return result;
        }
        if (nRows == 1) {
            return s;
        }
        int nIteration = (s.length() + nRows * 2 - 3) / (nRows * 2 - 2);
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; (j < nIteration) && (j * (nRows * 2 - 2) + i < s.length()); ++j) {
                result.push_back(s[j * (nRows * 2 - 2) + i]);
                if ((i != 0) && (i != nRows - 1) && ((j + 1) * (nRows * 2 - 2) - i < s.length())) {
                    result.push_back(s[(j + 1) * (nRows * 2 - 2) - i]);
                }
            }
        }
        return result;
    }
};