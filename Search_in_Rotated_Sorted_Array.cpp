class Solution {
public:
    int search(int A[], int n, int target) {
        int res;
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            if (A[0] == target) {
                return 0;
            }
            else return -1;
        }
        int left = A[0];
        int mid = n / 2;
        int midVal = A[mid];
        if (target == left) {
            return 0;
        }
        if (target == midVal) {
            return mid;
        }
        if (target < left) {
            if (target > midVal || midVal > left) {
                // right half
                res = search (&A[mid + 1], n - mid - 1, target);
                if (res == -1) {
                    return -1;
                }
                return res + mid + 1;
            }
            else {
                // left half
                res = search (A, mid, target);
                return res;
            }
        }
        else{
            // target > left
            if (target < midVal || midVal < left) {
                // left half
                res = search (A, mid, target);
                return res;
            }
            else {
                // right half
                res = search (&A[mid + 1], n - mid - 1, target);
                if (res == -1) {
                    return -1;
                }
                return res + mid + 1;
            }
        }
    }

};