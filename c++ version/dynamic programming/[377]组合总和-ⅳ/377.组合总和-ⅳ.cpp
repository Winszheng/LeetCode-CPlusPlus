/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start

// 定义dp[i]表总和为i的组合数
// 求总和为target的组合数，允许重复使用元素，不同顺序当做不同结果
// target做外循环
// nums做内循环
// 可以把重复还有顺序都考虑到

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];   
                }
            }
        }
        return dp[target];
    }
};

// @lc code=end

