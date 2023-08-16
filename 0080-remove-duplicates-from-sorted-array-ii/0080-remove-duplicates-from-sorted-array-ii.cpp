class Solution {
public:
int removeDuplicates(vector<int>& nums) {
  if(nums.size() <= 2){
    return nums.size();
  }
  int pointer = 0;
  for(int i=2;i<nums.size();i++){
    if(nums[i]!=nums[pointer]){
      nums[pointer+2] = nums[i];
      pointer++;
    }
  }
  return pointer+2;
}
};