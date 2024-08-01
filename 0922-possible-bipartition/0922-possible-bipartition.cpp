class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> hate(n, -1); // 0- no hate 1- hate
        vector<vector<int>> nolike(n);

        //zero based indexing 
        for (auto& d : dislikes) {
            nolike[d[0] - 1].push_back(d[1] - 1);
            nolike[d[1] - 1].push_back(d[0] - 1);
        }

        for (int i = 0; i < n; i++) {
            if (hate[i] == -1) {
                hate[i] = 0;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int size = q.size();
                    while (size--) {
                        int node = q.front();
                        q.pop();

                        for (const auto& n : nolike[node]) {
                            if (hate[n] == hate[node]) {
                                return false;
                            } else if (hate[n] == -1) {
                                hate[n] = !hate[node];
                                q.push(n);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

//1 based indexing 

/*
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> hate(n + 1, -1);
        vector<vector<int>> nolike(n + 1);

        for (auto& d : dislikes) {
            nolike[d[0]].push_back(d[1]);
            nolike[d[1]].push_back(d[0]);
        }

        for (int i = 1; i <= n; i++) {
            if (hate[i] == -1) {
                hate[i] = 0;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int size = q.size();
                    while (size--) {
                        int node = q.front();
                        q.pop();

                        for (const auto& n : nolike[node]) {
                            if (hate[n] == hate[node]) {
                                return false;
                            } else if (hate[n] == -1) {
                                hate[n] = !hate[node];
                                q.push(n);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
*/