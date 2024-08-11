#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int area = 0;
        while (left < right) {
            int temp_area = min(height[left], height[right]) * (right - left);
            area = max(area, temp_area);
            if (height[left] <= height[right]) {
                left++;
            } else if (height[left] >= height[right]) {
                right--;
            }
        }
        return area;
    }
};