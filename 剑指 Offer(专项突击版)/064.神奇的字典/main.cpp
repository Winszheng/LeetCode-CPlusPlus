#include <string>
#include <vector>
using namespace std;

// 初始想法，构造前缀树，然后用递归解
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
public:
    MagicDictionary() {
        hh = new trie();
    }
    void buildDict(vector<string> dictionary) {
        for(string s : dictionary)insert(s);
    }
    
    bool search(string searchWord) {
        int n = searchWord.size();
        // 字符串 正在探测 - 怎么tm每个事情倒霉都有我
        return to_search(searchWord, 0,)
    }
};

// 关于不一样这件事，应该怎么解决呢？
// 我的初始想法是递归，这时候递归的定义就变得很重要了。
