class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        int l, r;
        l = insertPos(A, n, target - 0.5);
        r = insertPos(A, n, target + 0.5);
        if (l < 0 || r < 0 || l == r) {
            return result;
        }
        else {
            result[0] = l;
            result[1] = r - 1;
            return result;
        }
    }
private:
    int insertPos (int A[], int n, double target) {
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
            return INT_MIN;
        }
        if (target < midVal) {
            return insertPos(A, midInd, target);
        }
        else {
            return midInd + 1 + insertPos(&A[midInd + 1], n - midInd - 1, target);
        }
    }
};