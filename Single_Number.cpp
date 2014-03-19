class Solution {
public:
    int singleNumber(int A[], int n) {
        int retval = 0;
        for (int i = 0; i < n; i++)
            retval = retval ^ A[i];
        return retval;
    }
};