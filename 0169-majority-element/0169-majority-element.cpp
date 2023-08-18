class Solution {
public:
    int majorityElement(vector<int>& nums) {
         unordered_map<int, int> ump;
         int n = nums.size();
         for(int i = 0; i<n;i++){
             ump[nums[i]]++;
         }

         for(auto it:ump){
             if(it.second > n/2){
                 return it.first;
                 break;
             }
         }
         return -1;
    }
};