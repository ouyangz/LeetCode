class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n <= 2) {
            if (s == "()")
                return 2;
            else
                return 0;
        }
        int result = 0;
        vector<int> height (n + 1,0);
        int lb = 0, rb = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                height[i + 1] = height[i] + 1;
            }
            else {
                height[i + 1] = height[i] - 1;
            }
        }
        
        while (lb < rb) {
            if (height[lb] >= height[rb]) {
                int tmp = lb + 1;
                while (tmp <= rb && height[tmp] >= height[lb]) {
                    tmp ++;
                }
                result = max (result, tmp - lb - 1);
                while (tmp <= rb && height[tmp] < height[tmp - 1]) {
                    tmp ++;
                }
                lb = tmp - 1;
            }
            else {
                int tmp = rb - 1;
                while (tmp >= lb && height[tmp] >= height[rb]) {
                    tmp --;
                }
                result = max (result, rb - tmp - 1);
                while (tmp >= lb && height[tmp] < height[tmp + 1]) {
                    tmp --;
                }
                rb = tmp + 1;
            }
        }
        return result;
    }
};