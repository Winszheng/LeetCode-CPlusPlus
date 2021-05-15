/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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



// 思路受之前做的“求bst中两节点的最近公共节点”启发
// 两个题本质是一样的，只是这道题拿走了bst无序这一条件
// 本质上，只要两个节点在root的一左一右，那么root就是最近公共节点(深度最深的公共节点)
// 因为无序，因此增加了一个函数，用来寻找子树中是否存在某节点

// 初始做法：
// result:
// Your runtime beats 5.53 % of cpp submissions
// Your memory usage beats 65.29 % of cpp submissions (13.9 MB)
// 搞了个get函数，没啥必要

// 优化版：
// Your runtime beats 39.27 % of cpp submissions
// Your memory usage beats 82.46 % of cpp submissions (13.9 MB)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;
        if(root == q || root == p)return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if(!left)return right;  // 单侧为空，证明p、q都在另一侧
        if(!right)return left;  // 而且根据递归定义，肯定是找到了
        return root;    // 两侧都不空，证明是一左一右，直接返回oot就可以了
    }
};
// @lc code=end

