class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int>mp;
        int single=-1;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==1){
                single=it.first;
            }
        }
        return single;
    }
};