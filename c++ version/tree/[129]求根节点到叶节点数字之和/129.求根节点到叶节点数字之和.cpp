/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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

// 这道题和之前几个题的思路是一模一样的
// 1.if空节点，直接返回
// 2.if非空，计算当前数字
//  2.1 if叶子节点，加和
//  2.2 if内部节点，继续做递归计算

// and：c++里的引用真方便，作为变量的别名省去了用指针的麻烦
class Solution {
    void resolve(TreeNode* root, int &sum, int temp){
        if(!root)return;
        temp = temp*10 + root->val;
        if(!root->left && !root->right){
            sum += temp;
        }else{
            resolve(root->left, sum, temp);
            resolve(root->right, sum, temp);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        resolve(root, sum, 0);
        return sum;
    }
};
// @lc code=end

