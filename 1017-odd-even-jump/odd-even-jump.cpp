class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        vector<int> next_odd_jump(n), next_even_jump(n);
        vector<pair<int, int>> sorted_arr(n);

        for (int i = 0; i < n; ++i) {
            sorted_arr[i] = {arr[i], i};
        }
        
        sort(sorted_arr.begin(), sorted_arr.end());

        stack<int> s;
        for (auto [a, i] : sorted_arr) {
            while (!s.empty() && s.top() < i) {
                next_odd_jump[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        for (int i = 0; i < n; ++i) {
            sorted_arr[i] = {-arr[i], i};
        }
        
        sort(sorted_arr.begin(), sorted_arr.end());

        while (!s.empty()) s.pop(); 

        for (auto [a, i] : sorted_arr) {
            while (!s.empty() && s.top() < i) {
                next_even_jump[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        vector<bool> odd(n, false), even(n, false);
        odd[n - 1] = even[n - 1] = true;

        for (int i = n - 2; i >= 0; --i) {
            odd[i] = (next_odd_jump[i] ? even[next_odd_jump[i]] : false);
            even[i] = (next_even_jump[i] ? odd[next_even_jump[i]] : false);
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (odd[i]) {
                ++count;
            }
        }

        return count;
    }
};
