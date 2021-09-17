// 时间效率很高，内存效率极低
class Solution {
    vector<int> re;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 节点为空，递归的终止条件
        if(!root)return re;

        inorderTraversal(root->left);
        re.push_back(root->val);
        inorderTraversal(root->right);
        return re;
    }
};