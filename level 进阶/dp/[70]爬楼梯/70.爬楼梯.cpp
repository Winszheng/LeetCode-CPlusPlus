/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <vector>
using namespace std;
// @lc code=start
// define dp[i] 为爬n阶梯的方法数，那么状态转移方程为
// dp[i] = dp[i-1] +dp[i-2];
// dp[0] = 0, dp[1] = 1, dp[2] = 2;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        if(n < 3)return n;
        dp[1]=1, dp[2]=2;
        for(int i = 3; i<n+1; i++)dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};
// @lc code=end

