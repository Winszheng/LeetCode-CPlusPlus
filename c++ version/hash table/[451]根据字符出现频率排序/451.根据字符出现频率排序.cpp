/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
#include <utility>
// @lc code=start
// 根据字符出现的频率排序
#include<map>
using namespace std;
class Solution {
    string reverse(string str){
        int l = 0, r = str.size()-1;
        while(l < r){
            swap(str[l], str[r]);
            l++, r--;
        }
        return str;
    }
public:
    string frequencySort(string s) {
        map<char, int> re;
        map<int, stack<char>> fre;
        string str = "";
        for(char c : s)re[c]++;
        for(auto a : re)fre[a.second].push(a.first);
        for(auto a : fre){
            while(!a.second.empty()){
                for(int i = 0; i < a.first; i++)str+=a.second.top();
                a.second.pop();
            }
        }
        str = reverse(str);
        return str;
    }
};
// @lc code=end

