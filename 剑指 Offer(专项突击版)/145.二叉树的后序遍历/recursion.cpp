class Solution {
    vector<int> re;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return re;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        re.push_back(root->val);
        return re;
    }
};