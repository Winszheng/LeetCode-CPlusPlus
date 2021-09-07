/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 二叉搜索树的最近公共祖先
// 二叉搜索树的特点：有序、递归定义
// 经过试验之后可以发现，只要p、q并没有在root节点的同一侧，那就相当于找到了最近公共节点
// 发现这个之后就很好做了
// 二叉树具有天然的递归结构
// 原先的做法稍微有点麻烦
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p)return p;
        if(root == q)return q;
        if(p->val > root->val && q->val > root->val)return lowestCommonAncestor(root->right, p, q);
        // return语句全都写在if或循环里，不可以
        return root;
    }
};
// @lc code=end

