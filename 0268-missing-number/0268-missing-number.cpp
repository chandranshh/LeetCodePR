class Solution {
public:
int missingNumber(vector<int>& nums) {
  int n = nums.size();
  if(n<1 && n>10e4){
    return -1;
  }
  int m=-1;

  vector<int> h(n+1);

  for(int i=0;i<n;i++){
    h[nums[i]]++;
  }

  for(int i=0;i<=n;i++){
    if(h[i]!=1){
      m=i;
    }
  }
  return m;
}

};