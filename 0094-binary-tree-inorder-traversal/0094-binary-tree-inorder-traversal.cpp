class Solution {
private:
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return;

        inorder(node->left, result);   // Visit left subtree
        result.push_back(node->val);  // Visit root
        inorder(node->right, result); // Visit right subtree
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};