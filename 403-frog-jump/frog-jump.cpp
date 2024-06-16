#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {

        unordered_set<int> stoneSet(stones.begin(), stones.end());

        unordered_map<int, unordered_map<int, bool>> memo;

        return canCrossHelper(stones, stoneSet, memo, 0, 0);
    }

private:
    bool canCrossHelper(vector<int>& stones, unordered_set<int>& stoneSet,
                        unordered_map<int, unordered_map<int, bool>>& memo,
                        int currentPosition, int lastJump) {
        if (currentPosition == stones.back()) {
            return true;
        }

        if (memo[currentPosition].count(lastJump)) {
            return memo[currentPosition][lastJump];
        }

        for (int jump = lastJump - 1; jump <= lastJump + 1; ++jump) {
            if (jump > 0) {
                int nextPosition = currentPosition + jump;
                if (stoneSet.count(nextPosition)) {
                    if (canCrossHelper(stones, stoneSet, memo, nextPosition,
                                       jump)) {
                        return memo[currentPosition][lastJump] = true;
                    }
                }
            }
        }
        return memo[currentPosition][lastJump] = false;
    }
};
