// 利用后序遍历修改指针的指向
// 时间效率100%
// 空间效率80%，还是比较理想
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return NULL;

        TreeNode *left = increasingBST(root->left);
        root->right = increasingBST(root->right);
        
        root->left = NULL;
        if(left){
            TreeNode *tmp = left;
            while(tmp->right)tmp = tmp->right;
            tmp->right = root;
            return left;
        }else return root;

    }
};