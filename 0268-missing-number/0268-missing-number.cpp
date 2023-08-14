class Solution {
public:
int missingNumber(vector<int>& nums) {
  int n = nums.size();

  if (n < 1 || n > 10e4) {
    return -1;
  }

  int totalSum = (n * (n + 1)) / 2;
  int actualSum = 0;
  for (int i = 0; i < n; i++) {
    actualSum += nums[i];
  }

  return totalSum - actualSum;
}
};