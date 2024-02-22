class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(auto num:nums){
            ump[num]++;
        }
        for(auto n:ump){
            if(n.second>=2){
                return true;
            }
        }
        return false;
    }
};