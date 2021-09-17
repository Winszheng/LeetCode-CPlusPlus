#include <queue>
using namespace std;

// 时空效率一般

class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* r) {
        root = r;
        q.push(root);
        while(q.front()->left && q.front()->right){ //这里是为了减少重复操作
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
        }
    }
    
    int insert(int v) {
        TreeNode* t = new TreeNode(v);
        while(q.front()->left && q.front()->right){
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
        }
        if(!q.front()->left){
            q.front()->left = t;
            return q.front()->val;
        }
        q.front()->right = t;
        return q.front()->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};