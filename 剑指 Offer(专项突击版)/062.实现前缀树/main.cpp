#include <string>
#include <vector>
using namespace std;

// 考的是数据结构：构造前缀树(字典树)
// 1.定义：字典树是一棵有根树、多叉树，对每个节点，包含以下字段:
    // a.孩子数组，一个vector，vector里是孩子指针
    // b.一个bool，表征是否是单词结尾
// 2.insert
// 从字典树的根部开始插入字符串，对当前操作的字符对应的数组，有两个可能
    // a.子节点存在，把指针移动到对应子节点，操作下一个字符
    // b.子节点不存在，插入相应字符
// 3.查找前缀
// 对每个要操作的字符，有两种情况
// a.子节点存在, 把指针移动到对应子节点，操作下一个字符
// b.子节点不存在，返回空指针

// 时间复杂度: 初始化为O(1)， 其他是O(n)，n是操作字符串的长度
// 空间复杂度: O(A*B), A:插入字符串的长度和 B:字符集大小，本题为26

class Trie {
    vector<Trie*> child;
    bool isend;
    // 搜索字符串，并返回对应末端节点。不存在，返回空
    Trie* to_search(string word){
        Trie* tail = this;
        for(char c : word) {
            int t = c - 'a';
            if(!tail->child[t])return NULL; //找不到对应字符串
            tail = tail->child[t];
        }
        return tail;    // 如果存在，则返回末端节点
    }
public:
    Trie(): child(26), isend(false){}
    
    void insert(string word) {  
        Trie* tail = this;
        for(char c : word){
            int t = c-'a';
            if(!tail->child[t])tail->child[t] = new Trie();
            tail = tail->child[t];  // 指向当前操作字符对应的节点
        }
        tail->isend = true;
    }
    
    bool search(string word) {
        auto temp = to_search(word);
        return temp && temp->isend;
    }

    bool startsWith(string prefix) {
        return to_search(prefix);
    }
};