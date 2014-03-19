class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> triplets;
        int n = num.size();
        if (n < 3) {
            return triplets;
        }
        sort(num.begin(), num.end());
        int prev = num[0] - 1;
        for (int i = 0; i< n - 2; ++i) {
            if (num[i] == prev) {
                continue;
            }
            int min = i + 1;
            int max = n - 1;
            int target = 0 - num[i];
            while (min < max) {
                if (num[min] + num[max] > target) {
                    max--;
                }
                else if (num[min] + num[max] < target) {
                    min++;
                }
                else {
                    vector<int> tri;
                    tri.push_back(num[i]);
                    tri.push_back(num[min]);
                    tri.push_back(num[max]);
                    triplets.push_back(tri);
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
            prev = num[i];
        }
        return triplets;
    }
};