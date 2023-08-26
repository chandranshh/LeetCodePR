class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    
    vector<int> prefixProducts(n);
    vector<int> suffixProducts(n);
    vector<int> answer(n);

    int product = 1;
    for (int i = 0; i < n; i++) {
        prefixProducts[i] = product;
        product *= nums[i];
    }

    product = 1;
    for (int i = n - 1; i >= 0; i--) {
        suffixProducts[i] = product;
        product *= nums[i];
    }

    for (int i = 0; i < n; i++) {
        answer[i] = prefixProducts[i] * suffixProducts[i];
    }

    return answer;
    }
};