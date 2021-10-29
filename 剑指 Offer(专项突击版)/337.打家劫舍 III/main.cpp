#include <unordered_map>
using namespace std;

// 1.树形dp，对每个节点，有选中、不选中两种状态
// 因为是树形dp，通过子树的最优解获取整棵树的最优解，所以是后序遍历-深搜
// 2.定义状态转移方程
// define fn: 选中根节点时，整个树能拿到的最优解
// define gn: 不选中根节点时，整棵树能拿到的最优解
// fn = n->val + g(l) + g(r)
// gn = max{f(l), g(l)} + max{f(r), g(r)}
class Solution {
    unordered_map<TreeNode*, int> f, g;
public:
    void dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);
        dfs(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);

    }
    
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};