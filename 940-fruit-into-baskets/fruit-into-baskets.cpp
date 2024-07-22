class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> ump;
        int left = 0, right = 0;
        int size = fruits.size();
        int maxi = 0;
        while (right < size) {
            ump[fruits[right]]++;
            while (ump.size() > 2) {
                ump[fruits[left]]--;
                if (ump[fruits[left]] == 0) {
                    ump.erase(fruits[left]);
                }
                left++;
            }
            if (ump.size() <= 2) {
                maxi = max(maxi, right - left + 1);
            }
            right++;
        }
        return maxi;
    }
};