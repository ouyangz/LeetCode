class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        string result;
        if (n == 0)
            return result;
        result = strs[0];
        int prefixlen = strs[0].length();
        for (int i = 0; i < n; i++) {
            string &cur = strs[i];
            int curlen = strs[i].size();
            for (int j = 0; j < prefixlen; j++) {
                if (j >= curlen || result[j] != cur[j]) {
                    result.resize(j);
                    prefixlen = j;
                    break;
                }
            }
        }
        return result;
    }
};