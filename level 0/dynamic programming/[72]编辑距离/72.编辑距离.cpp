/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
// 二维dp
// define dp[i][j] 表word[i]转换到word[j]所需的最小步数 —— 最优子结构嘛
// if word1[i] == word2[j], dp[i][j] = dp[i-1][j-1]
// else
// insert: dp[i][j] = dp[i][j-1] + 1;
// delete: dp[i][j] = dp[i-1][j] + 1;
// update: dp[i][j] = dp[i-1][j-1] + 1;

// 注意字符串和dp数组的对应关系
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i < n+1; i++)dp[i][0] = i;
        for(int j=1;j<m+1;j++)dp[0][j] = j;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(word1[i-1] == word2[j-1])dp[i][j] = dp[i-1][j-1];
                else{
                    int t = min(dp[i][j-1], dp[i-1][j]);
                    dp[i][j] = min(t, dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

