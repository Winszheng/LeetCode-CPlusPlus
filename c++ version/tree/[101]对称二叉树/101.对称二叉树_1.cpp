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
// 迭代完成对称二叉树——BFS层序遍历搭配
// 只要按恰当的方式入队，每次只要两两比较即可

// 官方的做法：相当于整体做了两次比较
// 修改之后：时间up，空间down，估计是因为这样空间开多了
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> q;
        q.push(root->left);q.push(root->right);
        while(!q.empty()){
            auto a = q.front(); q.pop();
            auto b = q.front(); q.pop();
            if(!a && !b)continue;
            if(!a || !b)return false;
            if(a->val != b->val)return false;

            q.push(a->left); q.push(b->right);
            q.push(a->right);q.push(b->left);
        }
        return true;
    }
};
// @lc code=end

