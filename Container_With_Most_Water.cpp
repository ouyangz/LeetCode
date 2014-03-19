class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        if (n <= 1) {
            return 0;
        }
        int left = 0;
        int right = n - 1;
        int mostWater = (right - left) * min(height[left], height[right]);
        while (left < right) {
            if (height[left] <= height[right]) {
                int temp = height[left];
                do {
                    left++;
                }while (left < right && height[left] < temp);
            }
            else {
                int temp = height[right];
                do {
                    right--;
                }while (left < right && height[right] < temp);
            }
            if ((right - left) * min(height[left], height[right]) > mostWater) {
               mostWater = (right - left) * min(height[left], height[right]);
            }
        }
        return mostWater;
    }
};