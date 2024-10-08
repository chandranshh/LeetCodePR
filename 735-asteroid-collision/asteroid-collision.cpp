class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0 || st.empty()) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0 &&
                       st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop();
                } else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }

        // finally we are returning the elements which remains in the stack. we
        // have to return them in reverse order.
        vector<int> res(st.size());
        for (int i = (int)st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};