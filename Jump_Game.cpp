class Solution {
public:
    bool canJump(int A[], int n) {
        int cur = 0;
        int mx = 1;
        while (mx < n && cur < n && cur < mx) {
            if (mx <= cur + A[cur]) {
                mx = cur + A[cur] + 1;
            }
            ++cur;
        }
        if (mx >= n) {
            return true;
        }
        else {
            return false;
        }
    }
};