/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
// 递归完成中序遍历
class Solution {
    void inorder(TreeNode* root, vector<int>& re){
        if(root){
            if(root->left)inorder(root->left, re);
            re.push_back(root->val);
            if(root->right)inorder(root->right, re);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        inorder(root, re);
        return re;
    }
};
// @lc code=end

