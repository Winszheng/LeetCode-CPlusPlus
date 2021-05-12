/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
// 求二叉树最大深度，初步思路是递归
// 39/39 cases passed (8 ms)
// Your runtime beats 82.16 % of cpp submissions
// Your memory usage beats 58.41 % of cpp submissions (18.4 MB)

// 这个题没什么必要分两个函数
class Solution {
    int recursion(TreeNode *root){
        if(!root)return 0;  // 递归终止条件，传入一棵空子树
        int a = recursion(root->left)+1;
        int b = recursion(root->right)+1;
        return a>b ? a : b;
    }
public:
    int maxDepth(TreeNode* root) {
        return recursion(root);
    }
};
// @lc code=end

