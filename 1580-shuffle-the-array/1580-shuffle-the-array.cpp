class Solution {
public:
 vector<int> shuffle(vector<int>& nums, int n) {
  if (n >= 1 && n <= 500) {
    auto arr = nums;
    int size = nums.size();
    if (size == 2 * n) {
  for (int i = 0; i < n; i++) {
    nums[i * 2] = arr[i];
    nums[(2 * i) + 1] = arr[n + i];
}
    }
  }
    return nums;
}
};