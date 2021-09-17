#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// 序列化和反序列化二叉树
// 按前序遍历压缩成字符串
// 按前序遍历反序列化成二叉树
// 递归解决

// 时间效率很高，但内存只有27.17%
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root)return "null";
        return to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right);
    }

    TreeNode* resolve(stringstream& ss){
        string tmp;
        ss>>tmp;
        if(tmp=="null")return NULL;
        TreeNode *root = new TreeNode(stoi(tmp));
        root->left = resolve(ss);
        root->right = resolve(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return resolve(ss);
    }
};

