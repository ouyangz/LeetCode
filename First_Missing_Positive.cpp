class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int m = n;
        for (int i = 0; i < m;) {
            if (A[i] <= 0) {
                m--;
                swap(A[i], A[m]);
            }
            else {
                i++;
            }
        }
        if (m == 0) {
            return 1;
        }
        int bound = m;
        for (int i = 0; i < bound;) {
            int cur = A[i];
            if (cur != i + 1) {
                if (cur > bound || A[cur - 1] == cur) {
                    bound --;
                    swap (A[i], A[bound]);
                }
                else {
                    swap(A[i], A[cur - 1]);
                }
            }
            else {
                i++;
            }
        }
        return bound + 1;
    }
};