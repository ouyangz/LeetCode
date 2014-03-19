class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int n = num.size();
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        vector<int> cur = num;
        result.push_back(cur);
        for (int i = 1; i < n; ++i) {
            for (int k = 0, end = result.size(); k < end; ++k) {
                vector<int> cur = result[k];
                for (int j = i; j > 0; --j) {
                    if (cur[j] == cur[j - 1]) {
                        break;
                    }
                    else {
                        swap(cur[j], cur[j - 1]);
                        result.push_back(cur);
                    }
                }
            }
        }
        return result;
    }
};