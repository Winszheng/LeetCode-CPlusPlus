/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
// 这是把之前的路径求和、找路径两个题结合起来了
// 二叉树具有天然的递归结构

class Solution {
    void resolve(TreeNode* root, vector<vector<int>>& re, vector<int> temp, int targetSum){
        if(!root)return;
        temp.push_back(root->val);
        if(root->val == targetSum && !root->left && !root->right)re.push_back(temp);
        else{
            resolve(root->left, re, temp, targetSum - root->val);
            resolve(root->right, re, temp, targetSum - root->val);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> re;
        resolve(root, re, {}, targetSum);
        return re;
    }
};
// @lc code=end

