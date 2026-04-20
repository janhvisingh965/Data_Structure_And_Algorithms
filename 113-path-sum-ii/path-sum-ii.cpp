class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == NULL) return;

        path.push_back(root->val);
        targetSum -= root->val;

        // leaf node
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == 0) {
                ans.push_back(path);
            }
        }

        dfs(root->left, targetSum, path);
        dfs(root->right, targetSum, path);

        path.pop_back(); // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }
};