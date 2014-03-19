class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        if (n < 3) {
            return INT_MAX;
        }
        int closest = num[0] + num[1] + num[n - 1];
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1;
            int r = n - 1;
            int prevDiff = num[i] + num[l] + num[r] - target;
            while (l < r) {
                int diff = num[i] + num[l] + num[r] - target;
                if (diff > 0) {
                    r--;
                    if (prevDiff < 0 && abs(prevDiff) < abs(closest - target)) {
                        closest = target + prevDiff;
                    }
                }
                else if (diff < 0) {
                    l++;
                    if (prevDiff > 0 && abs(prevDiff) < abs(closest - target)) {
                        closest = target + prevDiff;
                    }
                }
                else {
                    return target;
                }
                prevDiff = diff;
            }
            if (abs(prevDiff) < abs(closest - target)) {
                closest = target + prevDiff;
            }
        }
        return closest;
    }
};