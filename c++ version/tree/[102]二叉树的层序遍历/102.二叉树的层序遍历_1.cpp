/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
// 层序遍历二叉树——队列的使用——顶层到底层
// 本来的做法太憨了，只要保证每次遍历都刚刚好遍历整个一层就好了——借助队列
// 修改之后时间效率变化不大，空间效率明显变低，但是考虑到层序遍历类问题思路的一以贯之，我还是比较喜欢这种做法。
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> re;
        if(!root)return re;
        queue<TreeNode*> q;
        q.push(root);
        int index = -1;
        while(!q.empty()){
            int n = q.size();
            index++;
            re.push_back(vector<int>());
            for(int i = 0; i < n; i++){
                auto node = q.front();
                q.pop();
                re[index].push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return re;
    }
};
// @lc code=end

