class Solution {
public:
    string countAndSay(int n) {
        string input;
        string output("1");
        for (int i = 1; i < n; ++i) {
            input = output;
            output = "";
            int prev = input[0] - '0';
            int count = 1;
            for (int j = 1, end = input.size(); j < end; ++j) {
                int cur = input[j] - '0';
                if (cur != prev) {
                    output += to_string(count);
                    output += '0' + prev;
                    prev = cur;
                    count = 0;
                }
                count ++;
            }
            output += to_string(count);
            output += '0' + prev;
        }
        return output;
    }
};