#include <queue>
using namespace std;

// 求二叉树的右侧视图
// --- 利用队列层序遍历，记录每一层的最右节点
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> re;
        if(!root)return re;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* t = q.front();q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                if(i == n-1)re.push_back(t->val);
            }
        }
        return re;
    }
};