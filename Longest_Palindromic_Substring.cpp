class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		vector<int> evenP(n, 0);
		vector<int> oddP(n, 0);
		int evenMaxValue = 0;
		int evenMaxIndex = 0;
		int oddMaxValue = 0;
		int oddMaxIndex = 0;
		string result;

		for (int i = 0; i < n; ++i){
			int k = 1;
			// for Odd Palindrome
			while ((i - k >= 0) && (i + k < n) && (s[i - k] == s[i + k])){
				k++;
			}
			oddP[i] = k - 1;
			if (oddP[i] > oddMaxValue) {
				oddMaxValue = oddP[i];
				oddMaxIndex = i;
			}
			// for Even Palindrome
			k = 1;
			while ((i - k >= 0) && (i + k - 1 < n) && (s[i - k] == s[i + k - 1])) {
				k++;
			}
			evenP[i] = k - 1;
			if (evenP[i] > evenMaxValue) {
				evenMaxValue = evenP[i];
				evenMaxIndex = i;
			}
		}

		if ((2 * oddMaxValue + 1) > (2 * evenMaxValue)) {
			result.assign(s.begin() + oddMaxIndex - oddMaxValue, s.begin() + oddMaxIndex + oddMaxValue + 1);
		}
		else {
			result.assign(s.begin() + evenMaxIndex - evenMaxValue, s.begin() + evenMaxIndex + evenMaxValue);
		}

		return result;
	}
};