class Solution {
public:
    int sqrt(int x) {
        if (x < 0) {
            return -1;
        }
        if (x == 0) {
            return 0;
        }
        double result = x / 2.0;
        double previous = -1;
        while (fabs(result - previous) > 0.5) {
            previous = result;
            result = (result + x / result) / 2;
        }
        return (int(result));
    }
};