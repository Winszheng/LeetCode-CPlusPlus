#include <limits.h>
using namespace std;

// 求节点之和最大的路径，思路：
// 对于这道题，每个节点有两种状态
// 1.作为真正的根节点
// 2.作为子树的根节点
// 那么，很显然应该是后序遍历

// 空间效率很高，时间效率还行
// 递归的时间复杂度 = 递归的次数*每次递归中的操作次数
// 这里递归n次，每次递归的时间复杂度是1，所以整体的时间复杂度是O(n)
// 没有另外开辟内存空间，内存复杂度是1

class Solution {
public:
    int re = INT_MIN;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int ld = dfs(root->left);
        int rd = dfs(root->right);
        re = max(re, max(0, ld) + max(0, rd) + root->val);  // 作为根节点时，应有的结果
        return max(ld, rd)>0 ? root->val+max(rd, ld) : root->val;   // 作为子树时，应有的结果
    }
    int maxPathSum(TreeNode* root) {
      dfs(root);
      return re;
    }
};
