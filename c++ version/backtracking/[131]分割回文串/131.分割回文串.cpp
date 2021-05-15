/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串 palindrome partitioning
 */

// @lc code=start
// 分割回文串
// 分出来每个vector<string>表征一个分割结果
// 需要有个函数去判断分割出来的是不是回文串

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 初始做法：
// 在拷贝的逻辑上出了点问题——这个题做的是递归、回溯，基本上可以理解为一棵树不停分叉的树形过程，
// 而我在中途发现中间结果的时候，直接在当前进程做push_back，相当于把多叉树下游的结果放在了分叉之前，强行让所有孩子接收
// result: 304ms，两个效率都不超过10%，特别慢

// 我简称这种题为：树形分叉题，根节点为空，每条从根节点到叶子的路“权重”都相同，用回溯去做分割权重这件事
class Solution {
    bool isp(string s){
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l] != s[r])return false;
            l++, r--;
        } 
        return true;
    }

    void resolve(vector<vector<string>>& re, string s, int index, vector<string> temp, string t){
        if(t != "")temp.push_back(t);
        if(index == s.size()){
            re.push_back(temp);
            return;
        }
        for(int i = 1; i + index <= s.size(); i++){
            string ss = s.substr(index, i);
            if(isp(ss)){
                resolve(re, s, index+i, temp, ss);
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> re;
        resolve(re, s, 0, {}, "");  // {}表空vector
        return re;
    }
};

// @lc code=end

