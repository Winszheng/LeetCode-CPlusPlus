/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 左叶子之和——递归解法
// 1.如果节点为空，那么返回0
// 2.如果节点的后继包括左叶子，那么sum = 左叶子值 + 右子树的左叶子和
// 3.如果节点的后继没有左叶子，那么sum = 左子树的左叶子和 + 右子树的左叶子和
// 递归解法的关键是要捋清楚递归的终止条件和递归过程，也就是做好递归定义
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;  // 递归的结束条件
        if(root->left && !root->left->left && !root->left->right)return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
// @lc code=end

