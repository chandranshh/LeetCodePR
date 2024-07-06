class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_prod(n, 1);
        vector<int> suffix_prod(n, 1);
        vector<int> ans(n);

        prefix_prod[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_prod[i] = prefix_prod[i - 1] * nums[i];
        }

        suffix_prod[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_prod[i] = suffix_prod[i + 1] * nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = suffix_prod[i + 1];
            } else if (i == n - 1) {
                ans[i] = prefix_prod[i - 1];
            } else {
                ans[i] = prefix_prod[i - 1] * suffix_prod[i + 1];
            }
        }
        return ans;
    }
};
