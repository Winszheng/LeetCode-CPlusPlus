/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <vector>
using namespace std;
// @lc code=start
// dp 
// define dp[i]为以i结尾的最大子序和，如果dp[i-1]<0,dp[i]=nums[i]；否则，dp[i] = nums[i]+dp[i-1]
// dp[0] = nums[0];
// 并用个flag记录下所有解，返回最优

// 虽然这样能大幅提高时空效率，但是本质是一样的，没什么必要
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), re=nums[0], pre=nums[0];
        for(int i=1; i<n; i++){
            if(pre < 0)pre=nums[i];
            else pre=nums[i]+pre;
            re = max(re, pre);
        }
        return re;
    }
};
// @lc code=end
// Your runtime beats 21.4 % of cpp submissions
// Your memory usage beats 5.08 % of cpp submissions (13.1 MB)
// int maxSubArray(vector<int>& nums) {
//         int n=nums.size(), re=nums[0];
//         vector<int> dp(n, 0);dp[0]=nums[0];
//         for(int i=1; i<n; i++){
//             if(dp[i-1] < 0)dp[i]=nums[i];
//             else dp[i]=nums[i]+dp[i-1];
//             re = max(re, dp[i]);
//         }
//         return re;
//     }

