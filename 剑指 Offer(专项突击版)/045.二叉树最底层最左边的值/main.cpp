#include <queue>
using namespace std;
// 求二叉树最底层最左边的节点
// ==>求每一层的第一个节点

// 逐层入队列
// 每次都把当前层的第一个节点记录下来，并不断更新
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;q.push(root);
        int re = root->val;
        while(!q.empty()){
            bool flag = false;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode *t = q.front(); q.pop();
                if(!flag){
                    re = t->val;
                    flag = true;
                }
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return re;
    }
};