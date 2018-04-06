/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int sum, int cur) {
        cur += root->val;
        if ( cur == sum) {
            ans++;
        }
        if (root->left != NULL)
            dfs(root->left, sum, cur);
        if (root->right != NULL)
            dfs(root->right, sum, cur);
        cur -= root->val;

    }
    void driver(TreeNode* root, int sum) {
        int cur = 0;
        dfs(root, sum, cur);
        if (root-> left != NULL)
            driver(root->left, sum);
        if (root-> right != NULL)
            driver(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        driver(root, sum);
        return ans;
    }
};
