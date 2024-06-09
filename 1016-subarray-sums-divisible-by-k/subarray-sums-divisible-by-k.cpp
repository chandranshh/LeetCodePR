class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0, rem;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            rem = (sum % k + k) % k;
            mp[rem]++;
            if (mp[rem] > 1) {
                ans += mp[rem] - 1;
            }
        }
        return ans;
    }
};