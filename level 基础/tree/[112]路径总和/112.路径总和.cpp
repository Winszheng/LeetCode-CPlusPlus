/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
// 路径总和——迭代求解
// 用bfs做，队列里放节点和累计值，很简单也可以过，但是效率一般，看看别人怎么做
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;  // 这里属于题目没说清楚，题目的意思是只要进来的是空节点就算false
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, root->val));
        while(!q.empty()){
            auto t = q.front();q.pop();
            if(!t.first->left && !t.first->right && t.second == targetSum)return true;
            if(t.first->left)q.push(make_pair(t.first->left, t.second+t.first->left->val));
            if(t.first->right)q.push(make_pair(t.first->right, t.second+t.first->right->val));
        }
        return false;
    }
};
// @lc code=end

