class Solution {
public:
    int romanToInt(string s) {
        map<char, int> Rom2Num;
        Rom2Num['I'] = 1;
        Rom2Num['V'] = 5;
        Rom2Num['X'] = 10;
        Rom2Num['L'] = 50;
        Rom2Num['C'] = 100;
        Rom2Num['D'] = 500;
        Rom2Num['M'] = 1000;
        int n = s.length();
        int i = 0;
        int result = 0;
        while (i < n) {
            if (i + 1 < n && Rom2Num[s[i]] < Rom2Num[s[i+1]]) {
                result -= Rom2Num[s[i]];
            }
            else {
                result += Rom2Num[s[i]];
            }
            i++;
        }
        return result;
    }
};