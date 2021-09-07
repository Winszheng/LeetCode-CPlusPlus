/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
#include <vector>
using namespace std;

// 思路1：传统dp
// 把每天的状态划分为：
// 持有、不持有并处于冷冻期(今天卖了)、不持有且不处于冷冻期(之前卖的)
// 返回的只可能是后两种状态

// 没有一遍过，因为笔误
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][2]-prices[i], dp[i-1][0]);
            dp[i][1]=dp[i-1][0]+prices[i];
            dp[i][2]=max(dp[i-1][1], dp[i-1][2]);
        }
        return max(dp[n-1][1], dp[n-1][2]);
    }
};
// @lc code=end

