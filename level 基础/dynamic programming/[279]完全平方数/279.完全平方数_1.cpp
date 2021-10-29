/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start

// 方法2：dp，定义状态转移方程
// dp[i]存放组成i所需的最少的平方数，那么定义：
// 1.init dp[0] = 0, dp[1] = 1,dp[2] = 2, dp[3] = 3, dp[4] = 1
// 2.if n>=4
// for ever i in [4, n]
//  t = sqrt(n)
// if t*t == n, return 1
// else
// int nn = INT_MAX

// 思路和之前的题目是一样的，通过自顶向下不断分割问题
// 而代码是自底向上写的
// 总之是用小问题解决大问题

// 个人觉得这道题用广搜比较省事，效率也高一点
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        if(n<4)return n;
        dp[1]=1, dp[2]=2,dp[3]=3;
        for(int i=4;i<n+1;i++){
            int t = sqrt(i);
            if(t*t == i){
                dp[i] = 1;
                continue;
            }
            int temp = INT_MAX;
            for(int j=t; j>0;j--){
                temp = min(temp, 1+dp[i-j*j]);
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};

// @lc code=end

