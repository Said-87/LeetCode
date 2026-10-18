
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                level.push_back(current->val);

                if (current->left != nullptr)
                    q.push(current->left);

                if (current->right != nullptr)
                    q.push(current->right);
            }

            result.push_back(level);
        }

        return result;
    }
};
