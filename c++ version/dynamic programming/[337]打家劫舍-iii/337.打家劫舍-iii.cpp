/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
// 一开始居然做了层序遍历隔行求和这种zz行为...
// 典型树形dp，定义状态转移方程
// define fn : 选中根节点n时，整颗子树能拿到的最大权值
// define gn : 不选中根节点n时，整棵子树能拿到的最大权值
// f(n) = n->val + g(l) + g(r)
// g(n) = max{f(l), g(l)} + max{f(r), g(r)}

// 如何在树中模拟“从叶子节点迫近根节点”这件事 —— dfs

// Your runtime beats 52.49 % of cpp submissions
// Your memory usage beats 32.28 % of cpp submissions (28.1 MB)
// 因为用了递归和引入了map，所以空间效率和时间效率都一般般
class Solution {
    unordered_map<TreeNode*, int> f, g;
    void dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);
        dfs(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
    }
public:
    int rob(TreeNode* root) {
       dfs(root);
       return max(f[root], g[root]);
    }
};

// @lc code=end

