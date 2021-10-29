/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
// 核心：每个节点都可以成为头结点
// 原先的误区在于：把计算路径和 以及 每个节点都作为头结点计算路径和这两件事耦合了起来，造成了重复计算
// 这样做，思路也并不清晰

// 即，这道题合理的做法是：用两重递归完成递归定义
class Solution {
    int resolve(TreeNode *root, int target){
        if(!root)return 0;
        int re = 0;
        if(root->val == target)re++;
        re += resolve(root->left, target-root->val);
        re += resolve(root->right, target-root->val);
        return re;
    }
public:
    // 从root出发得到的结果+它的子树能拿到的所有结果
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        int re = 0;
        re += resolve(root, targetSum);

        re += pathSum(root->left, targetSum);
        re += pathSum(root->right, targetSum);

        return re;
    }
};
// @lc code=end

