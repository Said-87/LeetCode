
class Solution {
public:

    void flatten(TreeNode* root) {

        if (root == NULL) {
            return;
        }

        // Flatten left subtree
        flatten(root->left);

        // Flatten right subtree
        flatten(root->right);

        // Store right subtree
        TreeNode* temp = root->right;

        // Move left subtree to right
        root->right = root->left;

        // Make left NULL
        root->left = NULL;

        // Find the last node of the new right subtree
        TreeNode* current = root;

        while (current->right != NULL) {
            current = current->right;
        }

        // Attach original right subtree
        current->right = temp;
    }
};
