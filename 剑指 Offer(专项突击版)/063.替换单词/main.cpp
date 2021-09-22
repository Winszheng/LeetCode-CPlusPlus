#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

// 需要做的操作：
// 构造前缀树
// 对每个字符串，搜索前缀并构造回答

class Solution {
    struct trie{
        vector<trie*> child;
        bool isend;
        trie():child(26), isend(false){}
    };
public:
    trie *hh = new trie();
    void insert(string s){
        trie* tail = hh;
        for(char c : s){
            int t = c - 'a';
            if(!tail->child[t])tail->child[t] = new trie();
            tail = tail->child[t];
            if(tail->isend)return;
        }
        tail->isend = true;
    }
    
    // 如果对应字符不存在，返回原字符串
    // 如果存在，判断是否找到一个前缀，找到则返回，没找到则赋值下一个tail继续找
    string search(string temp){
        trie *tail = hh;
        for(int i=0; i<temp.size(); i++){
            int t = temp[i] - 'a';
            if(!tail->child[t])return temp;
            if(tail->child[t]->isend)return temp.substr(0, i+1);
            tail = tail->child[t];
        }
        return temp;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(string s : dictionary)insert(s);
        stringstream ss;ss.str(sentence);
        string temp, re = "";
        while(ss >> temp){
            string t = search(temp);
            if(re == "")re += t;
            else re = re + " " + t;
        }
        return re;
    }
};

int main(){
    vector<string> dictionary = {"cat","bat","rat"};
    Solution s;
    cout<<s.replaceWords(dictionary, "the cattle was rattled by the battery")<<endl;
}

