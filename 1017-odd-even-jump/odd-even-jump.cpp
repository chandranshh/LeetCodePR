class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        if (n <= 1) return n;

        vector<bool> odd(n, false), even(n, false);
        odd[n - 1] = true;
        even[n - 1] = true;

        // Sort by value then by index
        vector<pair<int, int>> Asort(n), Asort_rev(n);
        for (int i = 0; i < n; ++i) {
            Asort[i] = {A[i], i};
            Asort_rev[i] = {-A[i], i};
        }
        sort(Asort.begin(), Asort.end());
        sort(Asort_rev.begin(), Asort_rev.end());

        vector<int> oddjump = findJump(Asort);
        vector<int> evenjump = findJump(Asort_rev);

        int n_good = 1;

        // Traverse from second last to the first element
        for (int i = n - 2; i >= 0; --i) {
            // Odd jump
            int j = oddjump[i];
            if (j != -1) {
                odd[i] = even[j];
            }

            // Even jump
            j = evenjump[i];
            if (j != -1) {
                even[i] = odd[j];
            }

            // If we can make an odd jump from index i, increment the count
            if (odd[i]) {
                ++n_good;
            }
        }

        return n_good;
    }

private:
    vector<int> findJump(vector<pair<int, int>>& Asort) {
        int n = Asort.size();
        vector<int> jumpto(n, -1); // Initialize with -1 indicating no legal jump

        stack<int> stack;
        for (auto& [value, index] : Asort) {
            // Pop elements from stack smaller than current index
            while (!stack.empty() && stack.top() < index) {
                jumpto[stack.top()] = index;
                stack.pop();
            }
            stack.push(index);
        }

        return jumpto;
    }
};