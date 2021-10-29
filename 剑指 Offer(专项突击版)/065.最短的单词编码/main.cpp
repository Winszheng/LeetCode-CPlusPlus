#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// 题目意思： 把字符串翻转，记录前缀，相同前缀的情况下，只保留最长的字符串
// 考察前缀树的插入
// 在插入中，有两种情况
// 1.先操作了长的，短的字符串可以直接丢弃
// 2.先操作了短的，应把短字符串的数据舍弃
// 那么，在插入的过程中，不断记录真实插入到前缀树的字符串的数量和长度总和，如果当前插入的字符串不需要创建新节点，说明已存在，舍弃；
// 否则，一旦需要插入新节点，就把上一个节点表征的字符串长度和数量舍弃，记录新的数量和长度
class Solution {
public:
    int sum = 0;    // 长度
    int num = 0;    // 字符串数量
    struct trie{
        vector<trie*> child;
        bool isend;
        int len;
        trie():child(26), isend(false),len(0){}
    };
    trie *hh = new trie();
    void insert(string s){
        reverse(s.begin(), s.end());
        trie* tail = hh;
        bool add = false;   // 标记是否曾经新增节点；不需要新增节点，表明该字符串可以直接舍弃
        for(char c : s){
            int t = c-'a';
            if(tail->child[t])tail = tail->child[t];
            else {  // 孩子字符中没有相同的字符
                if(tail->isend){
                    tail->isend = false;num--;sum -= tail->len;
                }
                tail->child[t] = new trie();
                tail = tail->child[t];
                add = true;
            }
        }
        // 如果先操作长的再操作短的
        if(!add)return;
        tail->isend = true;num++;tail->len = s.size();sum+=s.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        for(string s : words)insert(s);
        cout<<"sum="<<sum<<", num="<<num<<endl;
        return sum+num;
    }
};

int main() {
    Solution s;
    vector<string> temp{"time", "me", "bell"};
    s.minimumLengthEncoding(temp);
}