/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
// 迭代后序遍历二叉树
// 问题在于，每次遇到“父”节点的时候。如何判断是应该弹出还是压入右子树
// 题解地址：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/a-li-mian-shi-ti-zhi-yong-zhan-qu-zuo-er-cha-shu-d/
#include<vector>
using namespace std;
//  整个操作相当于对二叉树做吞噬
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        stack<TreeNode*> s;
        if(!root)return {};
        s.push(root);
        while(!s.empty()){
            // 维护的栈是这样的结构
            // nullptr
            // |
            // node
            auto node = s.top();
            // 遇到nullptr，说明node之前应该输出的节点已经全部输出
            if(!node){
                s.pop();
                re.push_back(s.top()->val);
                s.pop();
                continue;
            }
            // 直接遇到节点，说明这个节点下属的孩子还没有全部输出
            s.push(nullptr);
            if(node->right)s.push(node->right);
            if(node->left)s.push(node->left);
        }
        return re;
    }
};
// @lc code=end

