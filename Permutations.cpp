class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int n = num.size();
        vector<vector<int>> result;
        if (n > 0)
        {
            result.push_back(num);
        }
        for (int i = 1; i < n; i++)
        {
            int k = result.size();
            for (int a = 0; a < k; a++)
            {
                vector<int> s = result[a];
                for (int j = i - 1; j >= 0; --j)
                {
                    swap(s[j], s[j + 1]);
                    result.push_back(s);
                }
            }
        }
        return result;
    }
};