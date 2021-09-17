// 因为bst的中序遍历是递增的
// 因此，可以设置一个pre记录上一个访问的节点，中序遍历
// 当pre等于要找的值时，就找到了目标节点

// 时空效率并不理想
class Solution {
    TreeNode *pre = NULL, *re = NULL;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root)return NULL;

        inorderSuccessor(root->left, p);
        if(pre == p)re = root;
        pre = root;
        inorderSuccessor(root->right, p);

        return re; // 存疑
    }
};