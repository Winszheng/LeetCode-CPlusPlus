/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum+target) % 2 == 1)return false;
        target = (sum+target)/2;
        // 在数组中，找到和为target的组合
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int n : nums){
            for(int i = target; i>= n; i--){
                dp[i] += dp[i-n];
            }
        }
        return dp[target];
    }
};
// @lc code=end

