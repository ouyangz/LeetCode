class Solution {
public:
    string addBinary(string a, string b) {
        list<char> rA;
        list<char> rB;
        list<char> rResult;
        for (string::iterator it = a.begin(); it != a.end(); ++it) {
            rA.push_front(*it);
        }
        for (string::iterator it = b.begin(); it != b.end(); ++it) {
            rB.push_front(*it);
        }
        int carry = 0;
        while (!rA.empty() && !rB.empty()) {
            int cur = rA.front() - '0' + rB.front() - '0' + carry;
            rResult.push_back('0' + cur % 2);
            carry = cur / 2;
            rA.pop_front();
            rB.pop_front();
        }
        while (!rA.empty()) {
            int cur = rA.front() - '0' + carry;
            rResult.push_back('0' + cur % 2);
            carry = cur / 2;
            rA.pop_front();
        }
        while (!rB.empty()) {
            int cur = rB.front() - '0' + carry;
            rResult.push_back('0' + cur % 2);
            carry = cur / 2;
            rB.pop_front();
        }
        if (carry != 0) {
            rResult.push_back('0' + carry);
        }
        string result;
        while(!rResult.empty()) {
            result += rResult.back();
            rResult.pop_back();
        }
        if (result.size() == 0) {
            result = "0";
        }
        return result;
    }
};