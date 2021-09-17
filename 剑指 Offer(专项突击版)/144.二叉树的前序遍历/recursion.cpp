
class Solution {
    vector<int> re;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // 节点为空
        // 递归的终止条件
        if(!root)return re; 

        re.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return re;
    }
};