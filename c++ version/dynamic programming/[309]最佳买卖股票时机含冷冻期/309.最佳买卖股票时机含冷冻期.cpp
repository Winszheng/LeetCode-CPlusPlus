/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start

// define f[i] 为第i日最优解
// 分类讨论，为了明确运算边界，以当日交易结束时间为状态划分界限
// 虽然可能有点违和，但是没问题
// 每天只可能有3种情况：买入、卖出、不操作（可能是接着持有或非冷冻期）
// define:
// - f[i][0]: 持有——要么今日买入，要么是之前买入
// - f[i][1]: 不持有，冷冻期，即：今天卖出
// - f[i][2]: 不持有，非冷冻期，即：昨天卖了，或更早之前卖了

// 虽然思路很明显，效率也很高，但是无论时间还是空间效率都很低
// 虽然可以只是简单用几个变量来解决，但是我觉得既然思路没变化，没什么必要
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = - p[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - p[i]);
            dp[i][1] = dp[i-1][0] + p[i];
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
        }
        return max(dp[n-1][1], dp[n-1][2]); // 最后一天的买入必然是亏，所以不用比，没意义
    }
};

// @lc code=end

