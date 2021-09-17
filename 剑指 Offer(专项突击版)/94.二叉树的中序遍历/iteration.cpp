#include <vector>
#include <stack>
using namespace std;
// 用迭代进行中序遍历
// 考虑中序遍历的访问顺序是 左 中 右
// 也就是对每一棵子树来说，第一个访问的是最左边的节点，那么就需要一个循环去找最左侧的节点
// 然后对栈顶做操作，记录数据并出栈，然后让指针指向右孩子

// 弯弯绕绕稍微多一丢丢，但是结果也比较理想
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> re;
       if(!root)return re;
       stack<TreeNode*> s;
       while(root || !s.empty()){
           while(root){
               s.push(root);
               root = root->left;
           }
           root = s.top(); s.pop();
           re.push_back(root->val);
           root = root->right;
       }
       return re;
    }
};