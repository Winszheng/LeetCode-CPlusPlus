/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
// 反转二叉树
// 思路是通过递归不断反转左右子树, 其实这道题只有第一层的返回值是有用的
// 用swap交换指针的指向，挺方便
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 递归的结束条件
        if(!root)return nullptr;
        // TreeNode *temp;
        // temp = root->left;
        // root->left = root->right;
        // root->right = temp; ok
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// @lc code=end

