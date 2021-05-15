/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
// 将有序数组转换为二叉搜索树
// 特点：二叉搜索树的中序遍历是严格递增的
// 本题做法受上一个题启发
// 思路：永远选择正中间，或中间偏右的节点作为根节点，这样得到的bst必然是平衡的

// 1.c++迭代器指定范围初始化，左闭右开
// 2.利用了递归的返回值
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size()/2;
        TreeNode *root = new TreeNode(nums[mid]);
        if(mid > 0){
            vector<int> t1(nums.begin(), nums.begin()+mid);
            root->left = sortedArrayToBST(t1);
        }
        if(mid < nums.size()-1){
            vector<int> t2(nums.begin()+mid+1, nums.end());
            root->right = sortedArrayToBST(t2);
        }
        return root;
    }
};
// @lc code=end

