// 相当于，把每个节点的值替换成它自己及其右子树的节点值的加和
// 把BST正常的中序遍历反过来，就是递减的中序遍历

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root){
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};