class Solution {
public:
    int maxSubArray(int A[], int n) {
        int cur = A[0];
        int max = A[0];
        for (int i = 1; i < n; ++i) {
            if (cur > 0) {
                cur += A[i];
            }
            else {
                cur = A[i];
            }
            if (cur > max) {
                max = cur;
            }
        }
        return max;
    }
};