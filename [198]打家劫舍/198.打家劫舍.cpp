/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

// 典型dp题，关键是找到状态转移方程
// 那么，状态转移方程？
// d[i]表[0~i]能得到的最优结果
// d[0] = nums[0], d[1] = max(nums[0], nums[1]), d[2] = nums[2] + d[0]
// 当i > 2时，d[i] = nums[i] + max(d[0] ~ d[i-2])
// 妙啊
// 直接用一个temp去存d[0]-d[i-2]当中的最大值就行了！
// 好像直接连数组都不需要啊
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), temp;
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};
// @lc code=end

