/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
// 0-1背包问题，不允许重复，倒序求解
// 完全背包问题，穷举重复，正序求解
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<long long> dp(amount+1, INT_MAX);
       dp[0] = 0;
       for(int n : coins){
           for(int i = n; i<= amount;i++){
               dp[i] = min(dp[i], dp[i-n]+1);
           }
       }
       return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end

