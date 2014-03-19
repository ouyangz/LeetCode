class Solution {
public:
    int climbStairs(int n) {
        int result = 1;
        int prev = 1;
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        for (int i = 2; i <= n; ++i) {
            int temp = result;
            result += prev;
            prev = temp;
        }
        return result;
    }
};