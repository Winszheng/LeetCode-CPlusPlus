// 查找二叉搜索树中国，第一个比给定节点大的后继，如果没有，返回NULL

// 因为二叉搜索树有序的特点，可以用一种类似二分查找的思路解决
// 如果p的值小于根节点的值，把返回节点置为根节点，把根节点置为左子树，在左子树中寻找结果
// 否则，说明如果有结果，肯定在右子树，把根节点置为右子树

// 相当于用二分搜索不断迫近结果
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* re = NULL;
        if(!root->left && !root->right)return re;

        while(root){
            if(root->val > p->val){
                re = root;
                root = root->left;
            }else {
                root = root->right;
            }
        }
        return re;
    }
};