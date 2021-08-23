/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
// 典型dp题
// 反复做错的原因是，状态转移方程分割得不对
// 定义fi为[1, i]个字符的所有decode方式
// if 对应字符!='0', fi += fi-1
// if 第i-1个字符 != 0 && 分割出来的结果小于26， 则fi += fi-2

// 写思路的时候不要纠结于详细实现
// 注意dp数组的i下标对应s的i-1下标
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i < n+1; i++){
            if(s[i-1]!='0')dp[i] +=dp[i-1];
            if(i>1 && s[i-2] != '0' && stoi(s.substr(i-2, 2)) < 27)dp[i] += dp[i-2];
        }
        return dp[n];
    }
};

// @lc code=end

