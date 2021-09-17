// 如果某棵子树的所有值都是0，那么这棵子树应该被剪掉
// 后序遍历解决(因为左右中次序，当此节点没有孩子且数据为0，一定可以删除)

// 因为操作的是改变指针指向，所以需要返回赋值，否则在上一层递归中，指针没有被改变
// 如果操作的是改变指针指向的内存的值，不必返回赋值
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return NULL;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(!root->left && !root->right && root->val==0)return NULL;

        return root;
    }
};

// wtm到底漏掉了什么没有想清楚？？？