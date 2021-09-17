// 中序遍历+双指针
// 虽然两种做法思路是一致的，但是双指针比哈希表的时空效率好很多
// 应该是因为中序遍历有序的特点吧
class Solution {
public:
    vector<int> re;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            re.push_back(root->val);
            inorder(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
       inorder(root);
       int l=0, r=re.size()-1;
       while(l<r){
           int t = re[l]+re[r];
           if(t == k)return true;
           else if(t < k)l++;
           else r--;
       }
       return false;
    }
};

// 只要思路是没有问题的，不就可以了？？？