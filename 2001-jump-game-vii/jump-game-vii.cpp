class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int size = s.size();
        
        if (s[size - 1] != '0') {
            return false;
        }
    
        vector<bool> dp(size, false);
        dp[size - 1] = true; 
        
        int cnt = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '1') {
                ++cnt;
                if (cnt >= maxJump) {
                    return false; 
                }
            } else {
                cnt = 0;
            }
        }

        for (int i = size - 2; i >= 0; --i) {
            if (s[i] == '0') {
                for (int jump = minJump; jump <= maxJump; ++jump) {
                    int dest = i + jump;
                    if (dest < size && dp[dest]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[0];
    }
};


// class Solution {
// public:
//     bool reach_helper(string s, int idx, int end, int minJump, int maxJump,
//                       vector<int>& dp) {
//         if (idx == end - 1 && s[idx] == '0') {
//             return true;
//         }
//         if (idx >= s.length() || s[idx] == '1') {
//             return false;
//         }
//         if (dp[idx] != -1) {
//             return dp[idx];
//         }

//         dp[idx] = false;

//         if (s[idx] == '0') {
//             for (int ind = idx + minJump; ind <= min(idx + maxJump, end - 1);
//                  ind++) {
//                 if (reach_helper(s, ind, end, minJump, maxJump, dp)) {
//                     return dp[idx] = true;
//                 }
//             }
//         }

//         return dp[idx];
//     }

//     bool canReach(string s, int minJump, int maxJump) {
//         int size = s.size();
//         int cnt = 0;
//         for (int i = 0; i < size; i++) {
//             if (s[i] == '1') {
//                 cnt++;
//                 if (cnt >= maxJump) {
//                     return false;
//                 }
//             } else {
//                 cnt = 0;
//             }
//         }

//         vector<int> dp(size + 1, -1);
//         return reach_helper(s, 0, size, minJump, maxJump, dp);
//     }
// };

// class Solution {
// public:
//     bool canReach(string s, int minJump, int maxJump) {
//         int size = s.size();
//         vector<bool> dp(size, false);

//         if(s[size - 1]!='0'){
//             return false;
//         }

//         dp[size - 1] = (s[size - 1] == '0');

//         for (int i = size - 2; i >= 0; --i) {
//             if (s[i] == '0') {
//                 for (int jump = minJump; jump <= maxJump; ++jump) {
//                     int dest = i + jump;
//                     if (dest < size && dp[dest]) {
//                         dp[i] = true;
//                         break;
//                     }
//                 }
//             }
//         }
//         return dp[0];
//     }
// };

// GIVIGN MEM LIMIT EXCEED
//  class Solution {
//  public:
//      bool reach_helper(string s, int idx, int end, int minJump, int maxJump,
//                        vector<int>& dp) {
//          if (idx == end - 1 && s[idx] == '0') {
//              return true;
//          }
//          if (s[idx] == '1') {
//              return false;
//          }
//          if (dp[idx] != -1) {
//              return dp[idx];
//          }

//         if (s[idx] == '0') {
//             for (int ind = idx + minJump; ind <= min(idx + maxJump, end - 1);
//                  ind++) {
//                 if (reach_helper(s, ind, end, minJump, maxJump, dp)) {
//                     return dp[idx] = true;
//                 }
//             }
//         }

//         return dp[idx] = false;
//     }
//     bool canReach(string s, int minJump, int maxJump) {
//         int size = s.size();
//         vector<int> dp(size + 1, -1);
//         return reach_helper(s, 0, size, minJump, maxJump, dp);
//     }
// };