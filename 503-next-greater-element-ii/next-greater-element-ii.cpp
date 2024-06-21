// comments for revision purpose
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // create a stack to store the elements
        stack<int> st;
        // get the size of the input vector
        int n = nums.size();
        // create a vector to store the answer
        vector<int> ans(n, -1);
        // iterate over the vector in reverse order, but wrap around to the
        // beginning when we reach the end
        for (int i = 2 * n - 1; i >= 0; i--) {
            // while the stack is not empty and the top element is less than or
            // equal to the current element
            while (!st.empty() && st.top() <= nums[i % n]) {
                // pop the top element from the stack
                st.pop();
            }
            // if the current index is within the bounds of the input vector
            if (i < n) {
                // if the stack is empty, set the answer for the current index
                // to -1
                if (st.empty()) {
                    ans[i] = -1;
                } else {
                    // otherwise, set the answer for the current index to the
                    // top element of the stack
                    ans[i] = st.top();
                }
            }
            // push the current element onto the stack
            st.push(nums[i % n]);
        }
        // return the answer vector
        return ans;
    }
};