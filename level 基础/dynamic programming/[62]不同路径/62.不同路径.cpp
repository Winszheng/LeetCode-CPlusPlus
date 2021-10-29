/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
// dp
// 第一个一遍过的dp题
// 本质是找：走到(i,j)个格子有几条路
// 因为条件是只能向下向右走，所以不能走回头路
// 那么状态转化规则就是：
// 到这个格子可以走的路径 = 到这个格子左边可以走的路 + 到这个格子上面可以走的路
// 把左边界和上边界初始化号好就行了
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++)dp[i][0] = 1;
        for(int i=0;i<n;i++)dp[0][i] = 1;

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

