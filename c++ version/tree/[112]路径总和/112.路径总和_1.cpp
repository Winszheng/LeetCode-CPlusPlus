/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
// 路径总和——递归求解
// 比迭代省事多了，时空效率也更高
// 用递归求解的时候，拿简单的模型、边界的条件去模拟coding
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       if(!root)return false;   // 特殊情况
       if(!root->left && !root->right && root->val == targetSum)return true;    // 递归的终止条件
       return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};
// @lc code=end

