class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> lastPosition;
		vector<int> distFromPrev(s.length(), 0);
		vector<int> longestSubstr(s.length(), 0);
		for (int i = 0; i < s.length(); ++i) {
			if (lastPosition.find(s[i]) != lastPosition.end()) {
				distFromPrev[i] = i - lastPosition[s[i]];
			}
			else {
				distFromPrev[i] = i + 1;
			}
			lastPosition[s[i]] = i;
		}

		if (s.length() == 0) {
			return 0;
		}

		longestSubstr[0] = 1;
		for (int i = 1; i < s.length(); ++i) {
			longestSubstr[i] = min(longestSubstr[i - 1] + 1, distFromPrev[i]);
		}

		return *max_element(longestSubstr.begin(), longestSubstr.end());
	}
};