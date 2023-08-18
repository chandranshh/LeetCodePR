class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;

        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        nums.clear();
        for(auto it : mp){
            for(int i=0;i<it.second;i++){
                nums.emplace_back(it.first);
            }
        }
    }
};