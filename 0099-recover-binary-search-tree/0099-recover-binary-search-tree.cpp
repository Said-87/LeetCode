
class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        // Find the misplaced nodes
        if (prev != nullptr && prev->val > root->val) {

            if (first == nullptr) {
                first = prev;
            }

            second = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        first = second = prev = nullptr;

        inorder(root);

        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
};
