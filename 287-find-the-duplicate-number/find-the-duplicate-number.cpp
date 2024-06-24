class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int m = -1;

        vector<int> h(n + 1);

        for (int i = 0; i < n; i++) {
            h[nums[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (h[i] > 1) {
                m = i;
            }
        }
        return m;
    }
};