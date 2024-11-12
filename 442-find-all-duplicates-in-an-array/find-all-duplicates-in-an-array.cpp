class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>hmp(n+1);
        vector<int>ans;
        for(int num : nums){
            hmp[num]++;
        }

        for(int i = 1; i <=n; i++){
            if(hmp[i] > 1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};