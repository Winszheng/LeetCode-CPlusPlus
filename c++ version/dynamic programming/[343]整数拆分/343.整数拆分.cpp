/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
// 这个题一看就要用dp，dp不难，做好定义就行了
// 定义dp[i]为i拆分可得的最大成绩，举例子后发现，对任意>=2的整数i，假定用j来做拆分，那么dp[i] = 
// - i*(i-j)    // 不拆分
// - i*dp[i-j]  // 拆分
// 这样，整个dp过程就变成了一个二重循环
// 状态转移方程：
// for(int j=1;j<i;j++)
// dp[i] = max(temp, max(j*(i-j), j*dp[i-j]))

// Your runtime beats 27.16 % of cpp submissions
// Your memory usage beats 70.15 % of cpp submissions (6 MB)

// 通过求解子问题的最优解，得到整个问题的最优解
// ——“最优子结构”
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0); // dp[1]\dp[0]直接定义为0
        for(int i=2;i<n+1;i++){
            int temp = 0;
            for(int j=1;j<i;j++){
                temp = max(temp, max(j*(i-j), j*dp[i-j]));
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};
// @lc code=end

