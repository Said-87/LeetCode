
class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> trees;

        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int i = start; i <= end; i++) {

            // Generate all possible left subtrees
            vector<TreeNode*> leftTrees = generate(start, i - 1);

            // Generate all possible right subtrees
            vector<TreeNode*> rightTrees = generate(i + 1, end);

            // Combine left and right subtrees
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* root = new TreeNode(i);

                    root->left = left;
                    root->right = right;

                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
