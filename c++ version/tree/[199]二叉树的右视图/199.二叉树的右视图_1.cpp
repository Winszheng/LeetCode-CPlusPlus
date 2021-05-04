/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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

#include <vector>
#include <queue>
using namespace std;

// 每次遍历，队列里刚刚好都只有一层的数据
// Your runtime beats 72.12 % of cpp submissions
// Your memory usage beats 68.78 % of cpp submissions (11.6 MB)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> re;
        queue<TreeNode*> q;
        if(!root)return re;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            TreeNode* node;
            for(int i=0;i<n;i++){
                node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            re.push_back(node->val);
        }
        return re;
    }
};
// @lc code=end

