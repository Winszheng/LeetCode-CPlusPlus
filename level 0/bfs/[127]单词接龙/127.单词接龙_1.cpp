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

// 机智的做法是利用广搜，自己生成一个无环无向图
// 通过这道题，加深了对c++的了解

// 对比：
// 本质上初始办法和改良版都是一个逻辑，但是初始办法会超时，因为做法是：每次取对首的一个元素，然后查剩下表中谁可以成为后继，是O(n^2)的做法，但是当数据上万的时候，就变得很慢
// 改良版是自行生成所有可能的后继，然后去查这个后继是否合法，利用了set自带的性质，因为第二第三重循环的规模是固定的(10/26)，所以这个办法实际上是O(n)的

// 总结就是：
// 1.unordered_set的查询速度比vector快多了
// 2.广搜的经典运用：在无权图中搜索最短路径。找法可以是遍历各种点或者自行生成点再去查
// 3.广搜的特点：只要找到结果，就是最短的，另外要避免走回头路
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if(wordset.find(endWord) == wordset.end())return 0;
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));    // 因为要求返回的是节点数量
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int re = q.front().second;
            q.pop();
            if(word == endWord)return re;
            for(int i=0;i<word.size();i++){
                string w = word;
                for(int j=0;j<26;j++){
                    w[i] = 'a'+j;    // 可以把c++里的string看成是char组成的
                    if(wordset.find(w)!=wordset.end() && visited.find(w)==visited.end()){
                        // 找到了新单词，并且这个新单词没有访问过
                        q.push(make_pair(w, re+1));
                        visited.insert(w);
                    }
                }
            }
        }
        return 0;   // 虽然循环走不到这里，但是少了这句会报错
    }
};

// @lc code=end

