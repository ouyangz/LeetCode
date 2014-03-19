class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, m;
        int n = num.size();
        if (n < 2) {
            return;
        }
        for (i = n - 1; i > 0; --i) {
            if (num[i - 1] < num[i]) {
                break;
            }
        }
        m = i;
        sort(num.begin() + m, num.end());
        if (m > 0) {
           for (int i = m; i < n; ++i) {
               if (num[m - 1] < num[i]) {
                   swap(num[m - 1], num[i]);
                   break;
               }
           }
        }
        return;
    }
};