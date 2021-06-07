/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
// 求最长公共子序列，明显是个dp
// 递归会超时
class Solution {
    int dp(string &a, string &b, int i, int j){
        if(i==-1 || j==-1)return 0;
        if(a[i] == b[j])return 1 + dp(a, b, i-1, j-1);
        return max(dp(a, b, i-1, j), dp(a, b, i, j-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return dp(text1, text2, text1.size()-1, text2.size()-1);
    }
};

// @lc code=end

