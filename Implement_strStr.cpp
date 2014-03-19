class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int i, j, n;
        n = 0;
        for (i = 0; needle[i] != 0; ++i) {
            n++;
        }
        int helper[n];
        helper[0] = -1;
        int match = -1;
        for (i = 1; i < n; ++i) {
            helper[i] = match + 1;
            if (needle[i] == needle[match + 1]) {
                match++;
            }
            else {
                match = -1;
            }
        }

        for (i = 0, j = 0; haystack[i] != 0 && j < n;) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                i -= helper[j];
                j = 0;
            }
        }
        if (j == n) {
            return (&haystack[i] - n);
        }
        else return NULL;
    }
};