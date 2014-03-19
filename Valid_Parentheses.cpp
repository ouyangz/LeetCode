class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        map<char, char> OtherP = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        set<char> Left = {'(', '{', '['};
        list<char> stack;

        for (int i = 0; i < n; ++i) {
            if (Left.count(s[i]) != 0) {
                stack.push_back(s[i]);
            }
            else if (s[i] == OtherP[*stack.rbegin()]) {
                stack.pop_back();
            }
            else {
                return false;
            }
        }
        if (stack.size() != 0) {
            return false;
        }
        else {
            return true;
        }
    }
};