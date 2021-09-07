/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
// 不太理解...但是过了
// 递归题要靠思路去做，不要过于纠结入栈出栈的详细过程
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;  // 递归结束条件
        if(!root->left && !root->right)return 1;    // 递归结束条件
        if(!root->left)return minDepth(root->right)+1;
        if(!root->right)return minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};
// @lc code=end

