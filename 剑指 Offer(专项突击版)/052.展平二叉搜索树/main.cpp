// 因为单边树本质上就是单链表，所以可以利用中序遍历生成节点
// 然而这样的时空效率非常一般

class Solution {
public:
TreeNode *hh = new TreeNode(-1), *tail = hh;
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return NULL;
        increasingBST(root->left);
        tail->right = new TreeNode(root->val);
        tail = tail->right;
        increasingBST(root->right);
        return hh->right;
    }
};