class Solution {
public:
    int trap(int A[], int n) {
        int result = 0;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            if (A[l] <= A[r]) {
                int i = l + 1;
                int top = A[l];
                while (i < r && A[i] <= top) {
                    result += top - A[i];
                    i++;
                }
                l = i;
            }
            else {
                int i = r - 1;
                int top = A[r];
                while (i > l && A[i] <= top) {
                    result += top - A[i];
                    i--;
                }
                r = i;
            }
        }
        return result;
    }
};