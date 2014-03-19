class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> quadruplets;
        int n = num.size();
        if (n < 4) {
            return quadruplets;
        }
        sort(num.begin(), num.end());
        int iprev = num[0] - 1;
        for (int i = 0; i< n - 3; ++i) {
            if (num[i] == iprev) {
                continue;
            }
            int jprev = num[i + 1] - 1;
            for (int j = i + 1; j< n - 2; ++j) {
                if (num[j] == jprev) {
                    continue;
                }
                int min = j + 1;
                int max = n - 1;
                int subTarget = target - num[i] - num[j];
                while (min < max) {
                    if (num[min] + num[max] > subTarget) {
                        max--;
                    }
                    else if (num[min] + num[max] < subTarget) {
                        min++;
                    }
                    else {
                        vector<int> quad;
                        quad.push_back(num[i]);
                        quad.push_back(num[j]);
                        quad.push_back(num[min]);
                        quad.push_back(num[max]);
                        quadruplets.push_back(quad);
                        int prevMinVal = num[min];
                        int prevMaxVal = num[max];
                        while (min < max && num[min] == prevMinVal) {
                            min++;
                        }
                        while (min < max && num[max] == prevMaxVal) {
                            max--;
                        }
                    }
                }
                jprev = num[j];
            }
            iprev = num[i];
        }
        return quadruplets;
    }
};