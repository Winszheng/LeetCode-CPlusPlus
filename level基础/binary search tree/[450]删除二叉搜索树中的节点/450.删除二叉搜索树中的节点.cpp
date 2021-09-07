/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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

// 删除二分搜索树中的指定节点
// 根据二分搜索树有序的性质：
// 1.如果目标节点值大于当前节点值，去右子树删除
// 2.如果目标节点值小于当前节点值，去左子树删除
// 3.如果目标节点就是当前节点，分类讨论：
//  3.1 左树为空，用右树直接顶替当前节点
//  3.2 右树为空，用左树直接顶替当前节点
//  3.3 左右树均在，找到右树最左叶子，把左树安到叶子下，右树顶替当前节点

// 注意这里要避免重复操作、修改指针指向问题
// 如果要修改的是指针指向节点的内容，直接改ok
// 如果要修改指针的指向，需要返回赋值，否则相当于只是修改了副本的指向，出系统栈之后等于白干...
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        // 如果这里不使用函数返回值来修改root->left，会报错——为啥？
        if(key < root->val)root->left = deleteNode(root->left, key);
        else if(key > root->val)root->right = deleteNode(root->right, key);
        else{
            if(!root->left)root = root->right;
            else if(!root->right)root = root->left;
            else{
                auto temp = root->right;
                while(temp->left)temp = temp->left;
                temp->left = root->left;
                root = root->right;
            }
        }
        return root;
    }
};
// @lc code=end

