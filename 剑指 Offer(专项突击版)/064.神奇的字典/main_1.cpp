#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

// 因为最多只需要操作100个单词，所以可以直接与给定的单词表做比较
// 完全相同或长度不同的直接不算
// 长度相同则比较不相同字符的个数，如果刚好为1，则是true
// 时间是O(n^2),空间O(S),S是给定单词表的大小

// 如果单词数量太多，这个时间复杂度可能会超时，但是这样构建出来的前缀树也小不到哪里去
// 只是搜索起来比较省事
class MagicDictionary {
public:
    vector<string> re;
    void buildDict(vector<string> dictionary) {
       re = dictionary;
    }
    
    bool search(string searchWord) {
        for(string s : re){
            if(searchWord == s || searchWord.size() != s.size())continue;

            int num = 0;
            for(int i=0;i<s.size() && num<2;i++){
                if(s[i] != searchWord[i])num++;
            }
            if(num == 1) return true;
        }
        return false;
    }
};
