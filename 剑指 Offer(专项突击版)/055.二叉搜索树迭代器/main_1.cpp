// 构造一个中序遍历迭代器
// 方法2: 中序遍历构造单边树, 时空效率非常高

class BSTIterator {
public: // 我写个tail是为了啥？
    TreeNode *hh = new TreeNode(-1), *tail = hh;

    TreeNode* inorder(TreeNode* root){
        if(!root)return NULL;

        TreeNode* left = inorder(root->left);
        root->right = inorder(root->right);
        if(left){
            TreeNode *tmp = left;
            while(tmp->right)tmp = tmp->right;
            tmp->right = root;
            return left;
        }else return root;

    }
    BSTIterator(TreeNode* root) {
        hh->right = inorder(root);
    }
    
    int next() {
       tail = tail->right;
       return tail->val;
    }
    
    bool hasNext() {
        if(!tail->right)return false;
        return true;
    }
};

