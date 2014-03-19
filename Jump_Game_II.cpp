class Solution {
public:
    int jump(int A[], int n) {
        int B[n];
        int mx = 1;
        B[0] = 0;
        for (int i = 0; i < n; ++i) {
            while (mx < n && mx <= i + A[i]) {
                B[mx] = B[i] + 1;
                ++mx;
            }
        }
        return B[n - 1];
    }
};