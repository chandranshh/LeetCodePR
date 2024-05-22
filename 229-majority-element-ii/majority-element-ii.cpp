class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      unordered_map<int, int> hash;
      vector<int>result;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        for(auto& pair : hash) {
            if(pair.second > n / 3) {
                result.push_back(pair.first);
            }
        }
        return result;   
    }
};