/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// 校验二分搜索树
// 二分搜索树的特点：按中序遍历得到的结果会是严格升序的

// 思路：
// 只要严格保持前驱节点 < 当前节点，就是bst
// 这个做法判断了整棵树的所有节点及其前驱
class Solution {
public:
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        auto left = isValidBST(root->left); // 获取当前节点的前驱节点
        if(pre && pre->val >= root->val)return false;
        pre = root;
        auto right = isValidBST(root->right);   
        return left && right;
    }
};
// @lc code=end

