class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        
       
        vector<int> prefixEven(n + 1, 0), prefixOdd(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                prefixEven[i + 1] = prefixEven[i] + nums[i];
                prefixOdd[i + 1] = prefixOdd[i];
            } else {
                prefixOdd[i + 1] = prefixOdd[i] + nums[i];
                prefixEven[i + 1] = prefixEven[i];
            }
        }
        
        int ways = 0;
        for (int i = 0; i < n; ++i) {
            
            int evenSum = prefixEven[i] + (prefixOdd[n] - prefixOdd[i + 1]);
            int oddSum = prefixOdd[i] + (prefixEven[n] - prefixEven[i + 1]);
            
            if (evenSum == oddSum) {
                ++ways;
            }
        }
        
        return ways;
    }
};
