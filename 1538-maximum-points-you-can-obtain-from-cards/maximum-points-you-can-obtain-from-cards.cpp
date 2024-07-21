class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int currSum = 0;

        // calculate the sum of the first k cards
        for (int i = 0; i < k; i++) {
            currSum += cardPoints[i];
        }

        int maxi = currSum;

        // use a sliding window to move cards from the end to the start
        for (int i = 0; i < k; i++) {
            currSum += cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            maxi = max(maxi, currSum);
        }

        return maxi;
    }
};
