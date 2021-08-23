/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
// 初步思路：中序遍历再返回
// 树的前中后序遍历其实都可以划到深度优先遍历当中
// Your runtime beats 92.66 % of cpp submissions
// Your memory usage beats 9.22 % of cpp submissions (23.9 MB)
// 提高空间效率的办法写起来比较麻烦，也没有提高很多，算了
class Solution {
    vector<int> re;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        re.push_back(root->val);
        inorder(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return re[k-1];
    }
};
// @lc code=end

