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
// 莫名奇妙就过了....先看看视频再看题解...这个题没什么必要分两个函数
// 改一下
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int a = maxDepth(root->left);
        int b = maxDepth(root->right);
        return max(a, b)+1;
    }
};
// @lc code=end

