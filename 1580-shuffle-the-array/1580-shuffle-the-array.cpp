class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
  vector<int>v;
  if (n >= 1 && n <= 500) {
    if (nums.size() == 2 * n) {
      for (int i = 0; i < n; i++) {
        v.emplace_back(nums[i]);
        v.emplace_back(nums[n + i]);
      }
    }
  }
  return v;
}
};