#include <string>
#include <vector>
using namespace std;

// 1.构造前缀树
//  - 孩子指针数组
//  - 标识字符串结束

// 2.递归解决搜索问题

// 时空效率都还可以
class MagicDictionary {
    struct trie{
        vector<trie*> child;
        bool isend;
        trie():child(26), isend(false){}
    };
    trie *hh;
    void insert(string s){
        trie* tail = hh;
        for(char c : s){
            int t = c-'a';
            if(!tail->child[t])tail->child[t] = new trie();
            tail = tail->child[t];  
        }
        tail->isend = true;
    }
    
    // 搜索的范围，是孩子
    bool dfs(trie* root, string &s, int index, int edit) {
        if(!root || edit > 1)return false;
        if(root->isend && index==s.size() && edit == 1)return true;
        
        int t = s[index] - 'a';
        int found = false;  // 是否找到符合条件的了

        for(int i=0; i<26 && !found; i++) {
            int temp_edit = (i==t && root->child[i]) ? edit : edit+1;
            found = dfs(root->child[i], s, index+1, temp_edit);
        }
        return found;
    }
public:
    MagicDictionary() {
        hh = new trie();
    }
    void buildDict(vector<string> dictionary) {
        for(string s : dictionary)insert(s);
    }
    // 要求有且仅有一个字符与字典中的不一样
    // 思路是用深度优先遍历来解决
    bool search(string searchWord) {
       return dfs(hh, searchWord, 0, 0);
    }
};

// 关于不一样这件事，应该怎么解决呢？
// 我的初始想法是递归，这时候递归的定义就变得很重要了。
