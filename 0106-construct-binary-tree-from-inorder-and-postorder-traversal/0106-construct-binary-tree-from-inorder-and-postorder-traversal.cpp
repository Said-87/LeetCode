
class Solution {
public:
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int left, int right) {
        if (left > right)
            return nullptr;

        int value = postorder[postIndex--];
        TreeNode* root = new TreeNode(value);

        int mid = mp[value];

        root->right = build(postorder, mid + 1, right);
        root->left = build(postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        mp.clear();

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }
};
