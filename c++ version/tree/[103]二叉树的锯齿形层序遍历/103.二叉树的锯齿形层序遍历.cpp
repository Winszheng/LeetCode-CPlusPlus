/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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


// 对二叉树做之字形层序遍历

// 层序遍历之后，对下标为odd的子数组做翻转
// 虽然方法有点笨但是效率还不错
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> re; // 记录遍历结果
        queue<pair<TreeNode*, int>> q;  //操作treenode入队出队
        if(!root)return re;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            // 获取队头——队头出队
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            // 记录队头
            if(re.size() == level)re.push_back(vector<int>());
            re[level].push_back(node->val);
            // 记录后继——后继入队
            if(node->left)q.push(make_pair(node->left, level+1));
            if(node->right)q.push(make_pair(node->right, level+1));
        }
        for(int i=0; i<re.size(); i++){
            if(i%2 == 1){
                int l=0, r=re[i].size()-1;
                while(l<r){
                    swap(re[i][l], re[i][r]);
                    l++, r--;
                }
            }
        }
        return re;
    }
};
// @lc code=end

