#include <vector>
#include <stack>
using namespace std;

// 迭代进行后序遍历，顺序：左右中
// 考虑到前序遍历是 中左右
// 那么只要把前序遍历的压栈顺序调换，出来的结果就是 中 右 左
// 然后再把结果翻转，就是后序遍历的样子

// 几乎双百
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        if(!root)return re;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* t = s.top();s.pop();
            re.push_back(t->val);
            if(t->left)s.push(t->left);
            if(t->right)s.push(t->right);
        }
        reverse(re.begin(), re.end());
        return re;
    }
};