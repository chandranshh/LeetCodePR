class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        set<int> s(nums.begin(), nums.end());

        int range_e = s.size() + 1;

        vector<unsigned long> h(range_e + 1);

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] <= range_e) {
                h[nums[i]]++;
            }
        }

        for (int i = 1; i <= range_e; i++) {
            if (h[i] == 0) {
                return i;
            }
        }

        return range_e;
    }
};
