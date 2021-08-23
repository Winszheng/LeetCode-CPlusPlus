/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
// 定义dp[i]为[0-i]上的最优解
// dp[i] = max(dp[i-1], nums[i]+dp[i-2])
// dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       if(n == 1)return nums[0];
       vector<int> dp(n, 0);
       dp[0]=nums[0], dp[1]=max(nums[0], nums[1]);
       for(int i=2; i<n; i++){
           dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
       }
       return dp[n-1];
    }
};



// @lc code=end

