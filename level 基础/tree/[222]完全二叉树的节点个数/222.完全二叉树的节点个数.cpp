/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
// 求complete tree的节点个数
// 思路：BFS，通过在队列入队出队来计算
// Your runtime beats 92.15 % of cpp submissions
// Your memory usage beats 13.87 % of cpp submissions (30.8 MB)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            auto a = q.front();q.pop();
            count++;
            if(a->left)q.push(a->left);
            if(a->right)q.push(a->right);
        }
        return count;
    }
};
// @lc code=end

