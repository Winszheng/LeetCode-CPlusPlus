#include <unordered_set>
using namespace std;
// 检查bst中是否有两数之和等于指定值
// 中序遍历+哈希存储已访问节点，如果找到了“两数之和”就返回true，否则返回false
// 时空效率很低，
class Solution {
public:
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        bool f1 = false, f2 = false;
        if(root){
            f1 = findTarget(root->left, k);
            if(s.count(k - root->val))return true;
            s.insert(root->val);
            f2 = findTarget(root->right, k);
        }
        return f1 || f2;
    }
};

