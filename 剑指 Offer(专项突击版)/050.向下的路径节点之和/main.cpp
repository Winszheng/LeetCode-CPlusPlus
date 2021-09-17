// 求向下的路径节点之和 - 双重dfs
// 双效率90%
// 前序遍历，把每个节点都当做根节点算一遍
class Solution {
public:
    int re = 0;
    void count(TreeNode *root, int target){
        if(!root)return;
        if(root->val == target)re++;
        count(root->left, target - root->val);
        count(root->right, target - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
       if(!root)return 0;

       count(root, targetSum);
       pathSum(root->left, targetSum);
       pathSum(root->right, targetSum);

       return re;

    }
};

// 这里一定存在重复计算的问题