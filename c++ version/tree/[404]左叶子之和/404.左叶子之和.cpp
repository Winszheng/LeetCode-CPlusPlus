/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
// 左叶子之和——迭代解法
// 关键是找到左叶子的父节点
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        int sum = 0;
        queue<TreeNode*> q;q.push(root);
        while(!q.empty()){
            auto t = q.front();q.pop();
            if(t->left&& !t->left->left && !t->left->right)sum+=t->left->val;
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
        return sum;
    }
};
// @lc code=end

