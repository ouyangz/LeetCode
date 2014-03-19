class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        vector<int>::reverse_iterator it = digits.rbegin();
        while (it != digits.rend() && carry != 0) {
            if (*it == 9) {
                *it = 0;
            }
            else {
                ++ (*it);
                carry = 0;
            }
            ++it;
        }
        if (carry != 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};