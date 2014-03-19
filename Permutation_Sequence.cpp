class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        int nPerm[10];
        nPerm[0] = 1;
        for (int i = 1; i <= n; ++i) {
            result += char('0' + i);
            nPerm[i] = i * nPerm[i - 1];
        }
        k = (k - 1) % nPerm[n];
        int start = 0;
        while (k > 0 && n > 1) {
            int first = k / nPerm[n - 1];
            char firstChar = result[start + first];
            for (int i = start + first; i > start; --i) {
                result[i] = result[i - 1];
            }
            result[start] = firstChar;
            k %= nPerm[n - 1];
            ++start;
            --n;
        }
        return result;
    }
};