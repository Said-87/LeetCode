
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;

        // Check if current node is a leaf
        if (root->left == NULL && root->right == NULL)
            return targetSum == root->val;

        // Subtract current node's value
        targetSum -= root->val;

        // Check left and right subtrees
        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};
