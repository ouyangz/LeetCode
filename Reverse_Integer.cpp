class Solution {
public:
    int reverse(int x) {
        int retsign = 1;
        int retval = 0;
        if (x == 0)
            return 0;
        if (x < 0){
            retsign = -1;
            x *= -1;
        }
        while (x != 0){
            retval = retval * 10 + x % 10;
            x = x / 10;
        }
        return retval * retsign;
    }
};