class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int res = 0;
        if (n == 0) {
            return 0; 
        }
        if (target < A[0]) {
            return 0;
        }
        if (target > A[n - 1]) {
            return n;
        }
        int midInd = n / 2;
        int midVal = A[midInd];
        if (target == midVal) {
            return midInd;
        }
        if (target < midVal) {
            return searchInsert(A, midInd, target);
        }
        else {
            return midInd + 1 + searchInsert(&A[midInd + 1], n - midInd - 1, target);
        }
    }
};