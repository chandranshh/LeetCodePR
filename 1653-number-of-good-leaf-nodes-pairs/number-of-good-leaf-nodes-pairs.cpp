class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        helper(root, distance, count);
        return count;
    }

private:
    vector<int> helper(TreeNode* root, int distance, int& count) {
        if (!root) return {};
        
        // If leaf node
        if (!root->left && !root->right) return {1};

        vector<int> leftDistances = helper(root->left, distance, count);
        vector<int> rightDistances = helper(root->right, distance, count);

        // Count pairs between left and right subtrees
        for (int ld : leftDistances) {
            for (int rd : rightDistances) {
                if (ld + rd <= distance) {
                    count++;
                }
            }
        }

        // Return distances for the current node
        vector<int> currentDistances;
        for (int ld : leftDistances) {
            if (ld + 1 < distance) {
                currentDistances.push_back(ld + 1);
            }
        }
        for (int rd : rightDistances) {
            if (rd + 1 < distance) {
                currentDistances.push_back(rd + 1);
            }
        }

        return currentDistances;
    }
};