class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            result.push_back("");
            return result;
        }
        char firstChar = digits[0];
        if (firstChar >= '0' && firstChar <= '9') {
            vector<string> rest = letterCombinations(digits.substr(1));
            string first = Code[firstChar];
            for (int i = 0, endi = rest.size(); i < endi; ++i) {
                for (int j = 0, endj = first.size(); j < endj; ++j) {
                    result.push_back(first[j] + rest[i]);
                }
            }
        }
        return result;
    }
    
private:
    set<char> Digit = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    map<char, string> Code = {{'0', " "}, {'1', "1"}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
};