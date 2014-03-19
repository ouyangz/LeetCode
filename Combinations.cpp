class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> stack;
        if (n < k) {
            return results;
        }
        for (int i = 1; i <= k; ++i) {
            stack.push_back(i);
        }
        while (true) {
            if (stack.size() == k) {
                results.push_back(stack);
                // find next
                while (stack.back() == n - k + stack.size()) {
                    stack.pop_back();
                }
                if (stack.empty()) {
                    break;
                }
                else {
                    ++ stack.back();
                }
            }
            else {
                stack.push_back(stack.back() + 1);
            }
        }
        return results;
    }
};