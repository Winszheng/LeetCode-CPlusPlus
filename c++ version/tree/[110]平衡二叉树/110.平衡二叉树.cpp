/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
// 要解决两件事：1是求各子树高度 2是确定各子树是否平衡树
// 思路是递归定义
// 递归确定树高度
// 递归确定树是否平衡二叉树
class Solution {
    int height(TreeNode* root){
        if(!root)return 0;
        return max(height(root->left), height(root->right))+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        return abs(height(root->left)-height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right); 
    }
};
// @lc code=end

