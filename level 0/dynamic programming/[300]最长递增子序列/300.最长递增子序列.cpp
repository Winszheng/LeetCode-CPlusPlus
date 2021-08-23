/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// 最长上升子序列 —— 典型dp
// define f[i] = 以n[i]结尾的最长上升子序列
// 然后返回最大的f[i]

// 感想：下标索引也挺费事
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n, 0);
       dp[0] = 1;
       int re = 1;
       for(int i=1;i<n;i++){
           int t = 0;
           for(int j=0;j<i;j++){
               if(nums[j] < nums[i]){
                   t = max(t, dp[j]);
               }
           }
           dp[i] = t + 1;
           re = max(re, dp[i]);
       }
       return re;
    }
};



// @lc code=end

