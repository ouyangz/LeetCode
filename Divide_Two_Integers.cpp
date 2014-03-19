class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        int sign = 1;
        unsigned int m, n; 
        if (divisor == 0) {
            throw;
        }
        if (dividend < 0) {
            sign = -sign;
            m = - dividend;
        }
        else {
            m = dividend;
        }
        if (divisor < 0) {
            sign = -sign;
            n = - divisor;
        }
        else {
            n = divisor;
        }
        while (m >= n) {
            long long x = n;
            long long y = 1;
            while (x <= m) {
                x <<= 1;
                y <<= 1;
            }
            x >>= 1;
            y >>= 1;
            result += y;
            m -= x;
        }
        if (sign > 0) {
            return result;
        }
        else {
            return -result;
        }
    }
};