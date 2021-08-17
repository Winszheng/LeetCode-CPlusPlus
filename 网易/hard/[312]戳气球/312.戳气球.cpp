/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
// 思路：
// 典型的dp，关键在找状态转移方程 —— 三重循环
// 外面两重是区间，第三重，k是当中要操作(戳破)的对象
// define dp[i][j] = max(dp[i][j], dp[i][k] +dp[k][j]+ nums[i]*nums[k]*nums[j])
// 1.初始，所有区间算数和为0
// 2.返回dp[0][n], 表(0, n)的最优解

// 题解：dp多重循环，很容易遇到关于“遍历次序的问题”
// 反不反过来只是计算顺序的问题， 关键是要从小区间转移到大区间
/**
 * dp版本代码，最外层的循环，i为什么是n-1 -> 0，而不能反过来？
 * (i,j) 0 1  2   3   4   ...   n-2   n-1   n   n+1
 * 0     0 1  2   3   4   ...                   n+1
 * 1       1  2   3   4   ...                   n+1
 * 2          2   3   4   ...                   n+1
 * 3              3   4   ...                   n+1
 * 4                  4                         n+1
 * .                      .                     .
 * .                         .                  .
 * n-2                          n-2   n-1   n   n+1
 * n-1                                n-1   n   n+1
 * n+1
 *
 * 须从下往上算，即先算dp[n-1][n+1]：
 * 根据递推关系，算dp[i][j]时依赖的dp[i][k]和dp[k][j]，其中i<k<j。
 * 1、如果从上往下计算，依赖的dp[k][j]根本就还未算出（k比i大），比如算dp[0][3]时，依赖的dp[1][3]还是个未知数。
 * 2、从下往上就不一样，算dp[i][j]时，依赖的dp[i][k]，位于同一行左侧，已计算过；
 *                                    依赖的dp[k][j]，因为k>i，位于更下面的行，也已计算过。
 */
// 解决思路是：从小范围转到大范围
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-2; i>=0; i--){  // dp的遍历次序，关键是从小范围转移到大范围，以此不断保存最优子结构
            for(int j=i+2;j<n;j++){
                for(int k=i+1;k<j;k++){
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
