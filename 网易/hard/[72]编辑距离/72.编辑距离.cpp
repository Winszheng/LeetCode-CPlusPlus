/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
// 这是个二维dp问题(最优子结构)
// define dp[i][j]表从word[i]转换到word[j]所需的最小步数
// if word[i] == word[j]:
//      dp[i][j] = dp[i-1][j-1] + 1
// else: 取以下操作的min
// insert: dp[i][j] = dp[i][j-1] + 1
// delete: dp[i][j] = dp[i-1][j] + 1
// update: dp[i]

// 更简洁的想法，取3个方向中的最小值+1

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<=n;i++)dp[i][0] = i;
        for(int j=0;j<=m;j++)dp[0][j] = j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1])dp[i][j] = dp[i-1][j-1];
                else{
                    int t = min(dp[i-1][j-1], dp[i-1][j]);
                    dp[i][j] = min(t, dp[i][j-1]) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

