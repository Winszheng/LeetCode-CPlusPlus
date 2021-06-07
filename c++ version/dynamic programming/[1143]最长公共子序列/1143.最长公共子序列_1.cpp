/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
// 典型的二维dp
// f[i][j]表(i, j)为最右最下顶点的二维范围中，最右的结果
// 也可以理解成贪心算法
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1;i<n+1;i++){
            char c = text1[i-1];
            for(int j=1;j<m+1;j++){
                if(c == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};


// @lc code=end

