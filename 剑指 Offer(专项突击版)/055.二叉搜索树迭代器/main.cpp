// 构造一个中序遍历迭代器
// 方法1： 用vector, 此时时空效率都挺低
class BSTIterator {
public:
    vector<int> re;
    int index = 0;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            re.push_back(root->val);
            inorder(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return re[index++];
    }
    
    bool hasNext() {
        if(index == re.size())return false;
        return true;
    }
};

