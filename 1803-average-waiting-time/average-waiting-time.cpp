class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double totalTime = 0.0;
        double currentTime = 0.0;

        for (const auto& customer : customers) {
            int arrival = customer[0];
            int processingTime = customer[1];

            if (currentTime <= arrival) {
                currentTime = arrival + processingTime;
            } else {
                currentTime += processingTime;
            }

            totalTime += currentTime - arrival;
        }

        return totalTime / n;
    }
};