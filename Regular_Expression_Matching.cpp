class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (p[0] == '\0') {
            if (s[0] == '\0')
                return true;
            else
                return false;
        }
        else if (p[1] != '*'){
            if (isCharMatch(s[0], p[0]))
                return isMatch(&s[1], &p[1]);
            else
                return false;
        }
        else {
            // p starts with '_*'
            // repeating 0 times
            if (isMatch(s, &p[2])) {
                return true;
            }
            int n = strlen(s);
            int r = 1;
            // repeating r times
            while (r <= n) {
                if (!isCharMatch(s[r-1], p[0]))
                    return false;
                else if (isMatch(&s[r], &p[2]))
                    return true;
                r++;
            }
            return false;
        }
    }
    
private:
    bool isCharMatch(const char s, const char p) {
        if (s == p) {
            return true;
        } 
        else if (s != '\0' && p == '.') {
            return true;
        }
        return false;
    }
};