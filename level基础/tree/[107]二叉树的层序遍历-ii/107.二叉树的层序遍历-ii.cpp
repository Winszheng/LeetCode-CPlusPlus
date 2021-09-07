/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
// 二叉树层序遍历——底层到顶层
// 层序遍历之后再翻转
// 层序遍历的思路
// 定义一个queue，记录每个节点及其层数
// 当queue不为空时，取出对应的节点和层数，pop掉这个节点
    // 记录遍历到的元素
    // 把后继加点压入队列

// 利用队列做层序遍历的思路：
// (1)队头出队，获取元素
// (2)记录元素
// (3)后继入队
// 循环直到结束

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> re;
        queue<pair<TreeNode*, int>> q;
        if(!root)return re;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level == re.size())re.push_back(vector<int>());
            re[level].push_back(node->val);
            if(node->left)q.push(make_pair(node->left, level+1));
            if(node->right)q.push(make_pair(node->right, level+1));
        }
        int l = 0, r = re.size()-1;
        while(l<r){
            swap(re[l], re[r]);
            l++,r--;
        }
        return re;
    }
};
// @lc code=end

