class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int n = S.size();
        int k = L.size();
        int len;
        vector<int> result;
        vector<int> dup(k, -1);
        map<string, int> words;
        vector<int> matched(n, -1);
        
        if (n == 0) {
            return result;
        }
        if (k == 0 || L[0].size() == 0) {
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
            return result;
        }
        len = L[0].size();
        sort(L.begin(), L.end());
        
        // Build dup
        int prevInd = 0;
        string prevVal = L[0];
        words[L[0]] = 0;
        for (int i = 1; i < k; ++i) {
            if (L[i] == prevVal){
                dup[i - 1] = i;
            }
            else {
                dup[i - 1] = prevInd;
                prevInd = i;
                prevVal = L[i];
                words[L[i]] = i;
            }
        }
        dup[k - 1] = prevInd;
        
        // Build matched[]
        for (int i = 0; i < len; ++i) {
            for (int j = i; j <= n - len; j += len) {
                string cur(S, j, len);
                if (words.count(cur) != 0) {
                    int ind = words[cur];
                    matched[j] = ind;
                    words[cur] = dup[ind];
                }
            }
        }
        
        // Find substr
        for (int i = 0; i < len; ++i) {
            vector<int> prev(k, -len);
            int count = 0;
            for (int j = i; j < n; j += len) {
                int cur = matched[j];
                if (cur == -1) {
                    count = 0;
                }
                else {
                    int diff = (j - prev[cur]) / len;
                    if (diff > count) {
                        count ++;
                    }
                    else {
                        count = diff;
                    }
                    prev[cur] = j;
                    if (count == k) {
                        result.push_back(j - len * (k - 1));
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};