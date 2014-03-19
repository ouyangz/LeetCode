class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int wordStart = 0;
        int result = 0;
        char prev = ' ';
        int i = 0;
        while(s[i]) {
            char cur = s[i];
            if (prev != ' ' && cur == ' ') {
                result = i - wordStart;
            }
            else if (prev == ' ' && cur != ' ') {
                wordStart = i;
            }
            prev = cur;
            ++i;
        }
        if (prev != ' ') {
            result = i - wordStart;
        }
        return result;
    }
};