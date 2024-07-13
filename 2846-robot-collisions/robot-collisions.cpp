class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ans(n, -1);
        vector<tuple<int, int, char, int>> robots; 
        
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

       
        sort(robots.begin(), robots.end());

        stack<pair<int, int>> st; 

        for (int i = 0; i < n; i++) {
            int pos = get<0>(robots[i]);
            int health = get<1>(robots[i]);
            char dir = get<2>(robots[i]);
            int index = get<3>(robots[i]);

            if (dir == 'R') {
                st.push({health, index});
            } else {
               
                while (!st.empty() && health > 0) {
                    auto [r_health, r_index] = st.top();
                    st.pop();

                    if (r_health > health) {
                        r_health -= 1;
                        health = 0;
                        if (r_health > 0) {
                            st.push({r_health, r_index});
                        }
                    } else if (r_health < health) {
                        health -= 1;
                    } else {
                        health = 0;
                    }
                }

                if (health > 0) {
                    ans[index] = health;
                }
            }
        }
        while (!st.empty()) {
            auto [r_health, r_index] = st.top();
            st.pop();
            ans[r_index] = r_health;
        }

        vector<int> result;
        for (int h : ans) {
            if (h != -1) {
                result.push_back(h);
            }
        }

        return result;
    }
};