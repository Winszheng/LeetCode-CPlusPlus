#include <string>
#include <vector>
using namespace std;

// 前缀树+bfs
// 然而内存效率比哈希表低很多

class MapSum {
public:
    struct trie{
        vector<trie*> child;
        int val;
        trie():child(26), val(0){}
    };
    trie *hh = new trie();
    MapSum() {
    }
    
    void insert(string key, int val) {
        trie *tail = hh;
        for(char c : key){
            int t = c-'a';
            if(!tail->child[t])tail->child[t] = new trie();
            tail = tail->child[t];
        }
        tail->val = val;
    }

    int bfs(trie* root){
        int re = root->val;
        for(int i=0;i<26;i++){
            if(root->child[i])re += bfs(root->child[i]);
        }
        return re;
    }
    
    int sum(string prefix) {
        trie *tail = hh;
        for(char c : prefix){
            int t = c-'a';
            if(!tail->child[t])return 0;    // 初始没考虑到：可能会输入非法的前缀
            tail = tail->child[t];
        }
        int re = tail->val;
        for(int i=0;i<26;i++){
            if(tail->child[i])re += bfs(tail->child[i]);
        }
        return re;
    }
};
