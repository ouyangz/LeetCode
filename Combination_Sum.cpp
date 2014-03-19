class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> vals;
        vector<int> inds;
        int curInd = 0;
        int n = candidates.size();
        int diff = target;
        while (true) {
            if (curInd == n || candidates[curInd] > diff) {
                if (inds.size() == 0) {
                    break;
                }
                int tempInd = inds.back();
                int tempVal = vals.back();
                inds.pop_back();
                vals.pop_back();
                diff += tempVal;
                curInd = tempInd + 1;
            }
            else {
                int curVal = candidates[curInd];
                inds.push_back(curInd);
                vals.push_back(curVal);
                diff -= curVal;
                if (diff == 0) {
                    result.push_back(vals);
                    curInd ++;
                }
            }
        }
        return result;
    }
};