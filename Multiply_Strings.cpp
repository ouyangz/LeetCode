class Solution {
public:
    string multiply(string num1, string num2) {
        string product;
        reverse(num1);
        reverse(num2);
        for (int i = 0, endi = num2.size(); i < endi; ++i) {
            string temp = rmultiplyDigit(num1, num2[i]);
            product = product.substr(0, i) + radd(product.substr(i), temp);
        }
        reverse(product);
        clean(product);
        return product;
    }
private:
    void reverse (string &s) {
        int n = s.size();
        for (int i = 0, end = n / 2; i < end; ++i) {
            swap(s[i], s[n - i - 1]);
        }
        return;
    }
    void clean(string &s) {
        int n = s.size();
        int m = 0;
        while (m < n - 1 && s[m] == '0') {
            m ++;
        }
        s = s.substr(m);
        return;
    }
    string radd (string num1, string num2) {
        int carry = 0;
        string result;
        int n1 = num1.size();
        int n2 = num2.size();
        int n = n1;
        if (n1 < n2) {
            num1 += string(n2 - n1, '0');
            n = n2;
        }
        if (n1 > n2) {
            num2 += string(n1 - n2, '0');
        }
        for (int i = 0; i < n; ++i) {
            int temp = carry + (num1[i] - '0') + (num2[i] - '0');
            result += temp % 10 + '0';
            carry = temp / 10;
        }
        if (carry != 0) {
            result += carry + '0';
        }
        return result;
    }
    
    string rmultiplyDigit(string num1, char num2) {
        string result;
        if (num2 == '0') {
            return "0";
        }
        if (num2 == '1') {
            return num1;
        }
        int carry = 0;
        for (int i = 0, end = num1.size(); i < end; ++i) {
            int temp = carry + (num1[i] - '0') * (num2 - '0');
            result += temp % 10 + '0';
            carry = temp / 10;
        }
        if (carry != 0) {
            result += carry + '0';
        }
        return result;
    }
    
};