class Solution {

private:
    void reverseFun(vector<int>& arr, int left, int right) {
        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverseFun(nums, 0, n - 1);
        reverseFun(nums, 0, k - 1);
        reverseFun(nums, k, n - 1);
    }
};