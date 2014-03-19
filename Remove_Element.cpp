class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int newlen = n;
        for (int i = 0; i < newlen; ++i) {
            if (A[i] == elem) {
                A[i] = A[newlen - 1];
                newlen--;
                i--;
            }
        }
        return newlen;
    }
};