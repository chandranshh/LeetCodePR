class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        int leftProduct = 1;
        int rightProduct = 1;

        for (int i = 0; i < n; i++) {
            answer[i] *= leftProduct;
            leftProduct *= nums[i];

            answer[n - 1 - i] *= rightProduct;
            rightProduct *= nums[n - 1 - i];
        }

        return answer;
    }
};
