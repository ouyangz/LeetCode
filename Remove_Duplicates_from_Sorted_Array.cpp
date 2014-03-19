class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) {
            return n;
        }
        int prev = A[0] - 1;
        int p = 0;
        int newlen = n;
        for (int i = 0; i < n; ++i) {
            if (A[i] == prev) {
                newlen--;
            }
            else {
                A[p] = A[i];
                p++;
                prev = A[i];
            }
        }
        return newlen;
    }
};