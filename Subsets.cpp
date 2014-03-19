class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        int n = S.size();
        vector<vector<int>> result;
        vector<int> cur;
        result.push_back(cur);
        for (int i = 0; i < n; ++i) {
            int Si = S[i];
            for (int j = 0, l = result.size(); j < l; ++j) {
                cur = result[j];
                cur.push_back(Si);
                result.push_back(cur);
            }
        }
        return(result);
    }
};