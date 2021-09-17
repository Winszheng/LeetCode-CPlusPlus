#include <stack>
#include <vector>
using namespace std;
// 前序遍历的迭代实现
// 用栈模拟递归操作
// 中 左 右
// 每次先处理栈顶，然后根据栈先进后出的特性，先右指针压栈，再左指针压栈
// 直到栈空
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> re;
        if(!root)return re;
        stack<TreeNode*> s;s.push(root);

        while(!s.empty()){
            TreeNode *t = s.top(); s.pop();
            re.push_back(t->val);
            if(t->right)s.push(t->right);
            if(t->left)s.push(t->left);
        }
        return re;
    }
};