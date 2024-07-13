class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        // Initialize vectors to store next jump indices
        vector<int> next_odd_jump(n), next_even_jump(n);
        // Create a vector of pairs to store element-value pairs with their indices
        vector<pair<int, int>> sorted_arr(n);

        // Populate sorted_arr with element-value pairs
        for (int i = 0; i < n; ++i) {
            sorted_arr[i] = {arr[i], i};
        }
        
        // Sort sorted_arr based on element values (ascending order)
        sort(sorted_arr.begin(), sorted_arr.end());

        stack<int> s;
        // Traverse sorted_arr to find next greater element for odd jumps
        for (auto [a, i] : sorted_arr) {
            // Maintain a monotonic stack to find the next greater element
            while (!s.empty() && s.top() < i) {
                next_odd_jump[s.top()] = i;  // Record the next greater element index
                s.pop();
            }
            s.push(i);  // Push current index onto the stack
        }

        // Prepare sorted_arr for finding next smaller element for even jumps
        for (int i = 0; i < n; ++i) {
            sorted_arr[i] = {-arr[i], i};  // Negate values for finding next smaller element
        }
        
        // Sort sorted_arr based on negated element values (ascending order)
        sort(sorted_arr.begin(), sorted_arr.end());

        while (!s.empty()) s.pop();  // Clear the stack

        // Traverse sorted_arr to find next greater element for even jumps
        for (auto [a, i] : sorted_arr) {
            // Maintain a monotonic stack to find the next greater element
            while (!s.empty() && s.top() < i) {
                next_even_jump[s.top()] = i;  // Record the next greater element index
                s.pop();
            }
            s.push(i);  // Push current index onto the stack
        }

        // Initialize vectors to track whether we can reach the end with odd and even jumps
        vector<bool> odd(n, false), even(n, false);
        odd[n - 1] = even[n - 1] = true;  // Initialize the last element as true for both vectors

        // Populate odd and even vectors based on next jump indices
        for (int i = n - 2; i >= 0; --i) {
            odd[i] = (next_odd_jump[i] ? even[next_odd_jump[i]] : false);  // Odd jump condition
            even[i] = (next_even_jump[i] ? odd[next_even_jump[i]] : false);  // Even jump condition
        }

        // Count the number of indices from where we can make odd jumps to reach the end
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (odd[i]) {
                ++count;
            }
        }

        return count;  // Return the count of valid starting indices for odd jumps
    }
};
