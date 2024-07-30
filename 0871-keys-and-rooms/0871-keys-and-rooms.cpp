class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();

        vector<bool> visited(size, false);

        queue<int> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int room = q.front();
                q.pop();

                for (auto key : rooms[room]) {
                    if (!visited[key]) {
                        visited[key] = true;
                        q.push(key);
                    }
                }
            }
        }
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};