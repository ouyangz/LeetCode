class Solution {
public:
    double pow(double x, int n) {
        int sign = 1;
        if (n < 0) {
            sign = -1;
            n *= -1;
        }
        double temp = x;
        double result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result *= temp;
            }
            temp *= temp;
            n /= 2;
        }
        if (sign == -1) {
            result = 1 / result;
        }
        return result;
    }
};