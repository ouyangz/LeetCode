class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        vector<int> inds;
        vector<int> vals;
        int diff = target;
        int curInd = 0;
        int n = num.size();
        int prevVal = num[n - 1];
        int prevInd = n - 1;
        vector<int> next(n);
        next[n - 1] = n;
        for (int i = n - 2; i >= 0; --i) {
            if (num[i] == prevVal) {
                next[i] = prevInd + 1;
            }
            else {
                next[i] = i + 1;
                prevVal = num[i];
                prevInd = i;
            }
        }
        while(true) {
            if (curInd == n || num[curInd] > diff) {
                if (inds.size() == 0) {
                    break;
                }
                curInd = next[inds.back()];
                diff += vals.back();
                inds.pop_back();
                vals.pop_back();
            }
            else {
                int curVal = num[curInd];
                inds.push_back(curInd);
                vals.push_back(curVal);
                diff -= curVal;
                if (diff == 0) {
                    result.push_back(vals);
                    curInd = next[curInd];
                }
                else {
                    curInd ++;
                }
            }
        }
        return result;
    }
};