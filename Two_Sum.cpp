class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> retval;
        set<int> s(numbers.begin(), numbers.end());
        for (vector<int>::iterator ita = numbers.begin(); ita != numbers.end(); ++ita){
            int other = target - *ita;
            if (s.find(other) != s.end()){
                for (vector<int>::iterator itb = ita + 1; itb != numbers.end(); ++itb){
                    if (*itb == other){
                        retval.push_back(ita - numbers.begin() + 1);
                        retval.push_back(itb - numbers.begin() + 1);
                        return retval;
                    }
                }
            }
        }
    }
};