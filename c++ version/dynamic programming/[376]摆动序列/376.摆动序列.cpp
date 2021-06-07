/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
// 求摆动序列的最长子序列长度
// define f[i]为选中第i个元素时，能得到的最优解
// f[i][0] : 子序列长度
// f[i][1] : i元素-i的前驱

// 1.时空效率非常低
// 2.思路不够简洁，容易因为细节出错
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 1;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        int re = 0;
        for(int i=1;i<n;i++){
            dp[i][1] = nums[i] - nums[0];
            if(dp[i][1] != 0)dp[i][0] = 2;
            else dp[i][0] = 1;
            re = max(re, dp[i][0]);
            for(int j=1;j<i;j++){
                if(dp[j][1] * (nums[i]-nums[j]) < 0 && dp[i][0] <= dp[j][0]){
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = nums[i] - nums[j];
                    re = max(re, dp[i][0]);
                }
            }
        }
        return re;
    }
};


// @lc code=end

