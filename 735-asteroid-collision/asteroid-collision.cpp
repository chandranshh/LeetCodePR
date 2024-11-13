class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) {
            bool pushAsteroid = true;
            
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (st.top() < -asteroid) {
                    st.pop(); // Top asteroid explodes
                    continue; // Continue to check the next top of the stack
                } else if (st.top() == -asteroid) {
                    st.pop(); // Both asteroids explode
                }
                pushAsteroid = false; // Current asteroid explodes
                break;
            }
            
            if (pushAsteroid) {
                st.push(asteroid);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};