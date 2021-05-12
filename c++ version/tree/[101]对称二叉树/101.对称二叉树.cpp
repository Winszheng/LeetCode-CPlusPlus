/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
// 递归完成对称二叉树
// 改了一句话之后，好理解多了
class Solution {
    bool check(TreeNode *a, TreeNode *b){
        if(!a && !b)return true;
        if(!a || !b)return false;
        return a->val==b->val && check(a->left, b->right) && check(a->right, b->left);

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return check(root->left, root->right);
    }
};
// @lc code=end

