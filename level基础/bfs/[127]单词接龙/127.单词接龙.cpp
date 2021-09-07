/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
    // 如何判断两个单词只差一个字母——用频率，一个地方少了1、一个地方多了1
    bool isnext(string root, string s){
        int n=0;
        for(int i=0;i<root.size();i++){
            if(root[i] != s[i])n++;
        }
        return n==1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // bool flag = false;
        // for(string s : wordList){
        //     if(s == endWord)flag = true;
        // }
        // if(!flag)return 0;
        unordered_set<string> worldset(wordList.begin(), wordList.end());
        if(worldset.find(endWord) == worldset.end())return 0;

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push(make_pair(beginWord, 0));
        visited.insert(beginWord);
        while(!q.empty()){
            string s = q.front().first;
            int d = q.front().second;
            q.pop();
            if(isnext(s, endWord))return d+2;
            for(int i=0; i< wordList.size(); i++){
                if(isnext(s, wordList[i]) && visited.find(wordList[i]) == visited.end() ){
                    q.push(make_pair(wordList[i], d+1));
                    visited.insert(wordList[i]);
                }
            }
        }
        // cout<<"3";
        return 0;
    }
};

// @lc code=end

