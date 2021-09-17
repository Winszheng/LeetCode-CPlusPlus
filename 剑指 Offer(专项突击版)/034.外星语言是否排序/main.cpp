#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 哈希表的简单使用 & 字典序，只需要依次检测相邻两个单词是否符合要求即可
// 关于字典序：
// 如果没有不一样的字符，那么短的字典序更靠前

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> re;
        int i=0;
        for(char c : order)re[c] = i++;
        int n=words.size();
        int l=0, r=1;
        while(r < n){
            string s1 = words[l];
            string s2 = words[r];
            int j=0;
            while(j<s1.size() && j<s2.size() && s1[j]==s2[j]){
                j++;
            }
            if((j==s1.size() || j==s2.size()) && s1.size() > s2.size()){
                return false;
            }
            if(re[s1[j]] > re[s2[j]]){  // 前面的权值应该更小
                return false;
            }
            l++, r++;
        }
        return true;

    }
};
