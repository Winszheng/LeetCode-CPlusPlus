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

// 关于二叉树层序遍历：
// 如果只是普通的遍历，例如自顶向下、自底向上、之字形遍历，其实不太需要讲究做法， 反正都能做
// 这道题，可以用遍历之后取最右的办法解，但是因为开了一个二维数组用来记录便利结果
// 空间效率会很低
// 但是题目根本不需要知道遍历结果，连层级也不需要知道
// 所以采取这种做法：每次刚刚好遍历一层节点，然后记录最右节点，即可

// 之前遍历用的办法并不是每次刚好遍历一层，虽然在之前的题目中，时空效率更高
// 但是却不适合这道题
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> re;
        queue<pair<TreeNode*, int>> q;
        vector<int> temp;
        if(!root)return temp;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            // 判断条件少写了一个‘=’，报错null pointer
            if(level == re.size())re.push_back(vector<int>());
            re[level].push_back(node->val);
            if(node->left)q.push(make_pair(node->left, level+1));
            if(node->right)q.push(make_pair(node->right, level+1));
        }
        for(auto arr : re){
            int i = arr.size()-1;
            temp.push_back(arr[i]);
        }
        return temp;
    }
};
// @lc code=end

