/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// 迭代完成前序遍历 —— 依靠栈
// 二叉树迭代遍历中，前序遍历是最简单的——因为不用考虑记录分层的事情
//也许中序遍历和后序遍历，需要和前序遍历对比着来看？
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> re;
        stack<TreeNode*> s;
        if(root)s.push(root);
        while(!s.empty()){
            auto temp = s.top();
            s.pop();
            re.push_back(temp->val);
            if(temp->right)s.push(temp->right);
            if(temp->left)s.push(temp->left);
        }
        return re;
    }
};

// @lc code=end