struct Robot {
    int position;
    int health;
    char direction;
    int index;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ans(n, -1);
        vector<Robot> robots;

       
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }


        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });

        stack<pair<int, int>> st; 
        for (int i = 0; i < n; i++) {
            int pos = robots[i].position;
            int health = robots[i].health;
            char dir = robots[i].direction;
            int index = robots[i].index;

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