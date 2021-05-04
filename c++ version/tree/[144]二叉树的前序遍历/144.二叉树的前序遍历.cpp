/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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

// 递归完成前序遍历
class Solution {
    void preorder(TreeNode* root, vector<int>& re){ // 注意要传引用，否则用的是拷贝
        if(root){
            re.push_back(root->val);
            if(root->left)preorder(root->left, re);
            if(root->right)preorder(root->right, re);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> re;
       preorder(root, re);
       return re;
    }
};
// @lc code=end

