// 前序遍历并累计结果
class Solution {
public:
    int dfs(TreeNode* root, int path){
        if(!root)return 0;
        path = path*10 + root->val;
        if(!root->left && !root->right)return path;

        return dfs(root->left, path) + dfs(root->right, path);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);        
    }
};

