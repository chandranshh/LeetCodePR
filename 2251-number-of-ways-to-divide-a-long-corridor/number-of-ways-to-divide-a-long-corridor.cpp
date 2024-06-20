class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> seats;
        int n = corridor.size();

        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S') {
                seats.push_back(i);
            }
        }

        int s_count = seats.size();

        // if the number of 'S' is odd or less than 2, no valid partition exists
        if (s_count < 2 || s_count % 2 != 0) {
            return 0;
        }

        // number of ways to partition the corridor
        long long ways = 1;
        const int MOD = 1e9 + 7;

        // calculate the number of ways to partition between every pair of 'S'
        for (int i = 2; i < s_count; i += 2) {
            int gap =
                seats[i] -
                seats[i - 1]; // used this because we are dealing in pairs of S
                              // so we just need to get the gap b/w two possible
                              // pairs and just multiply with prev ways because
                              // we are asked no of ways hence the
                              // multiplication, iteration is +2 because we'll
                              // be only hopping on pair of new S's
            ways = (ways * gap) % MOD;
        }

        return static_cast<int>(ways);
    }
};
