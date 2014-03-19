class Solution {
public:
    int atoi(const char *str) {
        int i = 0;
        int retsign = 1;
        long long retval = 0;
        while (str[i] != '\0' && isspace(str[i])) {
            i++;
        }
        if (str[i] == '-') {
            retsign = -1;
            i++;
        }
        else if (str[i] == '+') {
            i++;
        }
        while (str[i]>='0' && str[i] <= '9') {
            retval = retval * 10 + str[i] - '0';
            i++;
            if (retval * retsign > INT_MAX) {
                return INT_MAX;
            }
            else if (retval * retsign < INT_MIN) {
                return INT_MIN;
            }
        }
        return int(retval * retsign);
    }
};