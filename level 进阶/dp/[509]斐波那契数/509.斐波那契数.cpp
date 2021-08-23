/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
// 状态转移方程：dp[i] = dp[i-1] +dp[i-2], 初始值dp[0] = 0, dp[1] = 1;
class Solution {
public:
    int fib(int n) {
        if(n <2)return n;
        vector<int> dp(n+1, 0);
        dp[0] = 0, dp[1] =1;
        for(int i=2; i<n+1; i++)dp[i] = dp[i-1] +dp[i-2];
        return dp[n];
    }
};
// @lc code=end

