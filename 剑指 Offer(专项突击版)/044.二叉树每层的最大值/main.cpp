#include <vector>
#include <queue>
using namespace std;

// 求二叉树每层最大值 - 队列
// 要保证队列中的节点都非空
// 可以用队列做层序遍历

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if(!root)return ret;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int re = INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* t = q.front();q.pop();
                re = max(re, t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            ret.push_back(re);
        }
        return ret;
    }
};