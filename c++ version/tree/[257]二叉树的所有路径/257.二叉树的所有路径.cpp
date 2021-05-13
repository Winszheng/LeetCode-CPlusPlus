/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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

// 求二叉树的所有路径——经典的递归题
// 1.如果是空节点，返回空vector<string>
// 2.非空加入元素
//  2.1 如果是叶子，加入一条新路径
//  2.2 如果不是叶子，加入一个箭头
class Solution {
    void resolve(TreeNode *root, vector<string> &re, string path){
        if(!root)return;
        path += to_string(root->val);
        if(!root->left && !root->right)re.push_back(path);
        else{
            path += "->";
            resolve(root->left, re, path);
            resolve(root->right, re, path);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> re;
        resolve(root, re, "");
        return re;
    }
};
// @lc code=end

