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
// 事实证明用pair标记节点层级的效率高多了....
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       int index = -1;
       vector<vector<int>> re;
       if(!root)return re;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
           int n = q.size();
           index++;
           re.push_back(vector<int>());
           for(int i=0;i<n;i++){
               auto node = q.front();
               q.pop();
               re[index].push_back(node->val);
               if(node->left)q.push(node->left);
               if(node->right)q.push(node->right);
           }
           if(index%2 == 1){
               int l = 0, r = re[index].size()-1;
               while(l<r){
                   swap(re[index][l], re[index][r]);
                   l++, r--;
               }
           }
       }
       return re;
    }
};
// @lc code=end

