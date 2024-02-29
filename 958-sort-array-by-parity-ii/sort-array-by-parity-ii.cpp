class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);
        int j = 0, k = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                a[j] = nums[i];
                j += 2;
            } else if (nums[i] % 2 != 0) {
                a[k] = nums[i];
                k += 2;
            }
        }
        return a;
    }
};